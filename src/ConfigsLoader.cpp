

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
	(void)(argc);
	(void)(argv);
	(void)(envp);
}
