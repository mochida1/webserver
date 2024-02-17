

#include "main.hpp"
#include <iostream>

int init(int argc, char *argv[], char **envp){
	try{
		ArgumentValidator::validateArguments(argc, argv);
	}
	catch(const std::exception& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 1;
	}
	try{
		ArgumentValidator::checkEnvs(envp);
	}
	catch(const std::exception& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		return 2;
	}
	return 0;
}

int main (int argc, char *argv[], char **envp){
	int rc = 1;
	rc = init(argc, argv, envp);
	if (rc){
		return rc;
	}

	return 0;
}