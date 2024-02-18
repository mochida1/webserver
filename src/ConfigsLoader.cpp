

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
	this->_argc = argc;
	try{ 
		this->_pathToFile = this->_getPathToFileFromArgv(argv);
		this->_envs = this->_loadEnvsToMap(envp);
		this->_loadedConfigs = this->_readConfigsFromFile();
	}
	catch(const std::exception& e){
		return; //TODO - adicionar algo para fazer na exception!
	}
}

std::string ConfigsLoader::_getPathToFileFromArgv(char *argv[]){
	for (int i = 0; argv[i] != NULL; i++){
		std::string ret = argv[i];
		if (ret.find(CONSTRAINT_CONF_EXTENSION) != std::string::npos){
			return ret;
		}
	}
	throw ConfigsLoader::ConfigsLoaderException("Critical Error(ConfigsLoaderException): path to file not found in arguments!");
	return "";
}

const std::string ConfigsLoader::getPathToFile(void) const{
	return this->_pathToFile;
}

const std::vector<std::string> ConfigsLoader::getConfigsVector(void) const {
	return this->_loadedConfigs;
}

static const std::pair<std::string, std::string> getPairFromEnv(char *env) {
	std::pair<std::string, std::string> ret;
	std::string toSplit(env);
	size_t delimiterPos = toSplit.find_first_of('=');
	ret.first = toSplit.substr(0, delimiterPos);
	ret.second = toSplit.substr(delimiterPos + 1, toSplit.size());
	return ret;
}

std::map<std::string, std::string> ConfigsLoader::_loadEnvsToMap(char **envp){
	std::map<std::string, std::string> ret;
	for (int i = 0; envp[i] != NULL; i++){
		std::pair<std::string, std::string> keyValue = getPairFromEnv(envp[i]);
		ret.insert(keyValue);
	}
	return ret;
}


std::vector<std::string> ConfigsLoader::_readConfigsFromFile(void){
	unsigned int linesRead = 0;
	std::ifstream fileFS(this->_pathToFile.c_str());
	std::vector<std::string> lines;
	if (fileFS.is_open()){
		std::string line;
		while (std::getline(fileFS, line)){
			linesRead++;
			lines.push_back(line);
			line.clear();
		}
		fileFS.close();
	}
	else{
		std::string lError("Could not open file: ");
		lError.append(this->_pathToFile);
		throw ConfigsLoader::ConfigsLoaderException(lError);
	}
	if (linesRead == 0){
		std::string lError("Empty file: ");
		lError.append(this->_pathToFile);
		throw ConfigsLoader::ConfigsLoaderException(lError);
	}
	return lines;
}

