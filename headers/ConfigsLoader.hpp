

#pragma once
#ifndef CONFIGSLOADER_HPP
# define CONFIGSLOADER_HPP

#include <vector>
#include <map>
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>
#include "Constraints_webserv.hpp"
#include "DTO_Configs.hpp"

//WARNING: this class has some major memory overhead. 

class ConfigsLoader {
public:
	// OCF default destructor
	~ConfigsLoader(void);
	// OCF copy constructor
	ConfigsLoader(const ConfigsLoader & instance);
	// OCF assign operator overload
	ConfigsLoader & operator=(const ConfigsLoader & instance);
	// argument constructor
	ConfigsLoader(int argc, char *argv[], char **envp);

	// returns a map of configurations
	/* 
	deve ser const std::map<std::deque<std::pair<std::string, std::vector<std::string>>> fun() ou coisa do gênero. e não...
	 */
	DTO_Configs getConfigs(void) const;

	// Excpetion-----------
	class ConfigsLoaderException : public std::exception {
	public:
		// Constructor with a custom error message
		ConfigsLoaderException(const std::string& message) : errorMessage(message) {}

		// Override the what() function to provide the error message
		const char* what() const throw(){
			return errorMessage.c_str();
		}
		~ConfigsLoaderException() throw() {}
	private:
		std::string errorMessage;
	};
	

	// those are intended for testing. Do no use.
	const std::string getPathToFile(void) const ;
	const std::vector<std::string> getConfigsVector(void) const;
	const std::map<std::string, std::string> getEnvsMap(void) const;
	const std::vector<std::string> getExpandedConfigs(void) const;
	//---------------------
protected:
private:
	std::map<std::string, std::string> _getRequiredConfigs();
	std::vector<std::string> _readConfigsFromFile(void);
	std::string _getPathToFileFromArgv(char *argv[]);
	std::map<std::string, std::string> _loadEnvsToMap(char **envp);
	std::vector<std::string> _expandEnvs(void);
	void _expand_environment_variables(std::string &line);

	int _argc;
	std::string _pathToFile;
	std::map<std::string, std::string> _envs;
	std::vector<std::string> _loadedConfigs;
	std::vector<std::string> _expandedConfigs;

	
	// OCF default constructor
	ConfigsLoader(void);
};

#endif // CONFIGS_HPP