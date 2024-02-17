

#include "ConfigsLoader.hpp"

ConfigsLoader::ConfigsLoader(void){
	return ;
}

ConfigsLoader::~ConfigsLoader(void){
	return ;
}

ConfigsLoader::ConfigsLoader(const ConfigsLoader & instance){
	*this = instance;
}

ConfigsLoader & ConfigsLoader::operator=(const ConfigsLoader & instance){
	(void)(instance);
	return *this;
}

ConfigsLoader::ConfigsLoader(int argc, char *argv[], char **envp){
	this->_validateArguments(argc, argv);
	(void)(envp);
}

static bool checkArgcMinConstraint(int argc){
	if (argc < CONSTRAINT_ARGC_MIN_VALUE)
		return false;
	return true;
}

static bool checkArgcMaxConstraint(int argc){
	if (argc > CONSTRAINT_ARGC_MAX_VALUE)
		return false;
	return true;
}

void ConfigsLoader::_validateArguments(int argc, char *argv[]){
	if (!checkArgcMinConstraint(argc)){
		throw ConfigsLoader::ConfigsLoaderException(EARG_NOARGS);
	}
	else if (!checkArgcMaxConstraint(argc)){
		throw ConfigsLoader::ConfigsLoaderException(EARG_TOOMANYARGS);
	}
	return ;
	(void)(argv);
}