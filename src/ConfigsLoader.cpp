

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
	this->_pathToFile = this->_getPathToFileFromArgv(argv);
	this->_envs = this->_loadEnvsToMap(envp);
	this->_loadedConfigs = this->_readConfigsFromFile();
	this->_expandedConfigs = this->_expandEnvs();
	this->_noCommentsConfigs = this->_removeComments();
	this->_noCommentsConfigs = this->_trimAndRemoveEmpty();
	this->_DTO_Configs = this->_generateDTO();
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

const std::map<std::string, std::string> ConfigsLoader::getEnvsMap(void) const {
	return this->_envs;
}

const std::vector<std::string> ConfigsLoader::getExpandedConfigs(void) const {
	return this->_expandedConfigs;
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

static void _trim(std::string& str) {
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	
	if (first == std::string::npos || last == std::string::npos) {
		return ;
	}
	
	str = str.substr(first, last - first + 1);
}

void ConfigsLoader::_expand_environment_variables(std::string &line){
	_trim(line);
	if (line[line.size() - 1] == '$')
		throw ConfigsLoader::ConfigsLoaderException("Wrong formating, found $ at end of line.");
	size_t envStartPos = line.find_first_of('$');
	if(envStartPos == std::string::npos)
		return ;
	size_t envEndPos = line.find_first_of(" \r\t;", envStartPos);
	std::string toFind = line.substr(envStartPos, envEndPos);
	if (toFind.at(1) != '{' )
		toFind = toFind.substr(1, toFind.find_first_of(" \t\r;") - 1);
	else
		toFind = toFind.substr(2, toFind.find('}') - 2);

	std::string value = this->_envs.find(toFind)->second;
	if (value.empty())
		throw ConfigsLoader::ConfigsLoaderException("Missing environment variable: ["+ toFind +"]" );
	line.replace(envStartPos, envEndPos - envStartPos, value);
	this->_expand_environment_variables(line);
}

std::vector<std::string> ConfigsLoader::_expandEnvs(void){
	std::vector<std::string> ret;
	int lineCount = 0;
	for (std::vector<std::string>::iterator it = this->_loadedConfigs.begin(); it != this->_loadedConfigs.end(); it++){
		ret.push_back(*it);
		this->_expand_environment_variables(ret.back());
		lineCount++;
	}
	return ret;
}

std::vector<std::string> ConfigsLoader::_removeComments(void){
	std::vector<std::string> ret(this->_expandedConfigs);
	for (std::vector<std::string>::iterator line = ret.begin(); line != ret.end(); line++){
		size_t hashPos = line->find('#');
		if (hashPos == std::string::npos)
			continue;
		*line = line->substr(0, hashPos);
	}
	return ret;
}

const std::vector<std::string> ConfigsLoader::getNoCommentsConfigs(void) const{
	return this->_noCommentsConfigs;
}

//not the best solution ever, but it works :P
std::vector<std::string> ConfigsLoader::_trimAndRemoveEmpty(void){
	std::vector<std::string> ret;
	for (std::vector<std::string>::iterator line = this->_noCommentsConfigs.begin(); line != this->_noCommentsConfigs.end(); line++){
		_trim(*line);
		if (!line->empty())
			ret.push_back(*line);
	}
	return ret;
}

const DTO_Configs ConfigsLoader::getConfigs(void) const{
	return this->_DTO_Configs;
}

#include <iostream>
static std::vector<DTO_Configs> _populateLowerNestedContexts(size_t &line, std::vector<std::string> configsVector);

const DTO_Configs ConfigsLoader::_generateDTO(void) const{
	DTO_Configs ctx;
	ctx.name = "main";
	size_t it = 0;
	// we fill the first level of the DTO because it does not have a context name in the file
	while (this->_noCommentsConfigs[it].find('{') == std::string::npos && it < this->_noCommentsConfigs.size()) {
		std::vector<std::string> tokensVector;
		std::istringstream iss(this->_noCommentsConfigs[it]);
		std::string sToken;
		bool token_idx = false;
		std::string lKey;
		while (iss >> sToken){
			if (token_idx == false)
				lKey = sToken;
			else
				tokensVector.push_back(sToken);
			token_idx = true;
		}
		std::pair< std::string, std::vector<std::string> > value(lKey, tokensVector);
		ctx.property.insert(value);
		it++;
	}
	if (it < this->_noCommentsConfigs.size()) // do not populate context where it's not needed
		ctx.context = _populateLowerNestedContexts(it, this->_noCommentsConfigs);
	return ctx;
}

#include <cassert>

static std::string _getContextName(size_t line, std::vector<std::string> configsVector){
	return configsVector[line].substr(0, configsVector[line].find_first_of("{"));
}


static std::pair< std::string, std::vector<std::string> > _getPairPropertyFromLine(std::string line){
	std::vector<std::string> tokensVector;
		std::istringstream iss(line);
		std::string sToken;
		bool token_idx = false;
		std::string lKey;
		while (iss >> sToken){
			if (token_idx == false)
				lKey = sToken;
			else
				tokensVector.push_back(sToken);
			token_idx = true;
		}
	return std::pair< std::string, std::vector<std::string> >(lKey, tokensVector);
}

static std::vector<DTO_Configs> _populateLowerNestedContexts(size_t &line, std::vector<std::string> configsVector){
	std::vector<DTO_Configs> returnContext;
	// we must be sure we're always accessing the line where the context is declared
	if (configsVector[line].find('{') == std::string::npos){
		assert(0);
		return returnContext;
	}
	DTO_Configs currContext;
	currContext.name = _getContextName(line, configsVector);
	std::cerr << "ctxName: " << currContext.name << std::endl; //pega o nome
	// std::cerr << "{{ opened braces" << std::endl;
	bool isBraceOpen = true;
	line++;
	// search for this level properties
	while (line < configsVector.size()){
		// if a new nested context was found
		if (configsVector[line].find('{') != std::string::npos  && isBraceOpen == false){
			currContext.context = _populateLowerNestedContexts(line, configsVector);
			isBraceOpen = true;
		}
		else if (configsVector[line].find('{') != std::string::npos){
			currContext.name = _getContextName(line, configsVector);
			line++;
		}
		// if we reached the end of a context, adds it to contexts vector
		else if (configsVector[line].find('}') != std::string::npos){
			line++;
			returnContext.push_back(currContext);
			currContext.name.clear();
			currContext.property.clear();
			currContext.context.clear();
			// std::cerr << "closed braces }}" << std::endl;
			isBraceOpen = false;
		}
		else{ //we fill the current context with it's properties content
			currContext.property.insert(_getPairPropertyFromLine(configsVector[line]));
			std::cerr << "PropKey:[" << _getPairPropertyFromLine(configsVector[line]).first << "]\t\tPropValue: { ";
			for (size_t i = 0; i < _getPairPropertyFromLine(configsVector[line]).second.size(); i++){
				std::cerr << _getPairPropertyFromLine(configsVector[line]).second[i] << " ";
			}
			std::cerr << "}" << std::endl;
			line++;
		}
	}
	return returnContext;
}



