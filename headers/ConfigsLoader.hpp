

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


	const std::string getPathToFile(void) const ;
	const std::vector<std::string> getConfigsVector(void) const;
	// returns a map of configurations
	/* 
	deve ser const std::map<std::deque<std::pair<std::string, std::vector<std::string>>> fun() ou coisa do gênero. e não...
	const std::map<std::string, std::string> getConfigs(void);
	 */
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
	//---------------------
protected:
private:
	std::map<std::string, std::string> _getRequiredConfigs();
	std::vector<std::string> _readConfigsFromFile(void);
	std::string _getPathToFileFromArgv(char *argv[]);
	std::map<std::string, std::string> _loadEnvsToMap(char **envp);
	void _expandEnvs();

	int _argc;
	std::string _pathToFile;
	std::map<std::string, std::string> _envs;
	std::vector<std::string> _loadedConfigs;

	
	// OCF default constructor
	ConfigsLoader(void);
};

#endif // CONFIGS_HPP