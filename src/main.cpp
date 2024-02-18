

#include "main.hpp"


static bool shouldDaemonize(char *argv[]){
	std::set<std::string> arguments;
	for (int i = 1; argv[i] != NULL; i++){
		std::string arg(argv[i]);
		if (arguments.insert(arg).second == false){
			throw ArgumentValidator::ArgumentValidatorException("Oh shit. Something really fucked up happened!");
		}
	}

	for (std::set<std::string>::iterator it =  arguments.begin(); it != arguments.end(); it++ ) {
		if (it->compare("-d") == 0) {
			return true;
		}
	}
	return false;
}

static unsigned char daemonize() {
	// Fork the process
	pid_t pid = fork();

	if (pid < 0) {
		// Fork error
		return(EXIT_FAILURE);
	}

	// If we got a good PID, then we can exit the parent process.
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	// Create a new session
	if (setsid() < 0) {
		// setsid error
		return(EXIT_FAILURE);
	}

	// Fork again to ensure the daemon cannot re-acquire a controlling terminal
	pid = fork();

	if (pid < 0) {
		// Fork error
		return(EXIT_FAILURE);
	}

	// If we got a good PID, then we can exit the parent process.
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	// Change the working directory to root
	if (chdir("/") < 0) {
		// chdir error
		return(EXIT_FAILURE);
	}

	// Close all open file descriptors
	for (int fd = sysconf(_SC_OPEN_MAX); fd > 0; --fd) {
		close(fd);
	}

	// Redirect standard file descriptors
	freopen("/dev/null", "r", stdin);
	freopen("/dev/null", "w", stdout);
	freopen("/dev/null", "w", stderr);

	// Now the process is daemonized
	return 0;
}

static int init(int argc, char *argv[], char **envp){
	try{
		ArgumentValidator::validateArguments(argc, argv);
		ArgumentValidator::checkEnvs(envp);
	}
	catch(const std::exception& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 1;
	}
	if (shouldDaemonize(argv))
		if(daemonize())
			return 4;
	ConfigsLoader CL(argc, argv, envp);
	return 0;
}

int main (int argc, char *argv[], char **envp){
	int rc = 0;
	rc |= init(argc, argv, envp);
	
	if (rc){
		return rc;
	}
	return 0;
}