
#include "ArgumentValidator.hpp"

static bool checkArgcMinConstraint(int argc) {
	if (argc < CONSTRAINT_ARGC_MIN_VALUE)
		return false;
	return true;
}

static bool checkArgcMaxConstraint(int argc) {
	if (argc > CONSTRAINT_ARGC_MAX_VALUE)
		return false;
	return true;
}

static bool compareValidArgumentFlags(std::string toCompare) {
	const unsigned char numberOfEntries = 6;
	const std::string validEntries[numberOfEntries] = {"-d", "-h", "--logLevel=0", "--logLevel=1", "--logLevel=2", "--logLevel=3"};
	for (unsigned char i = 0; i < numberOfEntries; i++){
		if(validEntries[i].compare(toCompare) == 0){
			return true;
		}
	}
	return false;
}

static bool checkArgumentsFormat(int argc, char *argv[]) {
	std::set<std::string> arguments;

	//skip this phase if we forced argc to be higher than it should be
	int skip = 0;
	for (skip = 0; argv[skip] != NULL; skip++){;}
	if (skip >= 2 && skip < argc)
		return true;

	// inserts arguments into a set. Every one of them must be unique. We skip program name
	for (int i = 1; i < argc; i++){
		std::string arg(argv[i]);
		if (arguments.insert(arg).second == false){
			return false;
		}
	}

	for (std::set<std::string>::iterator it =  arguments.begin(); it != arguments.end(); it++ ) {
		if (it->find(CONSTRAINT_CONF_EXTENSION) == std::string::npos) {
			if (!compareValidArgumentFlags(*it))
				return false;
		}
	}
	return true;
}

static bool checkArgumentsForDoubleConf(char *argv[]){
	std::set<std::string> arguments;
	for (int i = 1; argv[i] != NULL; i++){
		std::string arg(argv[i]);
		if (arguments.insert(arg).second == false){
			throw ArgumentValidator::ArgumentValidatorException("Oh shit. Something really fucked up happened!");
		}
	}

	bool foundDotConf = false;
	for (std::set<std::string>::iterator it =  arguments.begin(); it != arguments.end(); it++ ) {
		if (it->find(CONSTRAINT_CONF_EXTENSION) != std::string::npos) {
			if (foundDotConf == true)
				return false;
			foundDotConf = true;
		}
	}
	return true;
}

static int accessFileStatus(char *argv[]){
	std::set<std::string> arguments;
	for (int i = 1; argv[i] != NULL; i++){
		std::string arg(argv[i]);
		if (arguments.insert(arg).second == false){
			throw ArgumentValidator::ArgumentValidatorException("Oh shit. Something really fucked up happened!");
		}
	}

	std::string pathToFile;
	for (std::set<std::string>::iterator it =  arguments.begin(); it != arguments.end(); it++ ) {
		if (it->find(CONSTRAINT_CONF_EXTENSION) != std::string::npos) {
			pathToFile = *it;
			break;
		}
	}

	if ( access(pathToFile.c_str(), R_OK | F_OK) ){
		return errno;
	}
	return 0;
}

bool ArgumentValidator::checkEnvs(char **envp){
	int i;
	for (i = 0; envp[i] != NULL; i++);
	if (!i)
		throw ArgumentValidator::ArgumentValidatorException(EARG_NOENVS);
	return true;
}

void ArgumentValidator::validateArguments(int argc, char *argv[]) {
	if (!checkArgcMinConstraint(argc)) {
		throw ArgumentValidator::ArgumentValidatorException(EARG_NOARGS);
	}
	else if (!checkArgcMaxConstraint(argc)) {
		throw ArgumentValidator::ArgumentValidatorException(EARG_TOOMANYARGS);
	}
	else if(!checkArgumentsFormat(argc, argv)) {
		throw ArgumentValidator::ArgumentValidatorException(EARG_WRONGARGS);
	}
	else if(!checkArgumentsForDoubleConf(argv)) {
		throw ArgumentValidator::ArgumentValidatorException(EARG_DOUBLECONF);
	}
	int rc = -1;
	rc = accessFileStatus(argv);
	if (rc)
		throw ArgumentValidator::ArgumentValidatorException(std::strerror(errno));

	return ;
}