

#pragma once
#ifndef CONFIGSLOADER_HPP
# define CONFIGSLOADER_HPP

#include <vector>
#include <map>
#include <string>
#include <exception>
#include <stdexcept>

class ConfigsLoader {
public:
	// OCF default constructor
	ConfigsLoader(void);
	// OCF default destructor
	~ConfigsLoader(void);
	// OCF copy constructor
	ConfigsLoader(const ConfigsLoader & instance);
	// OCF assign operator overload
	ConfigsLoader & operator=(const ConfigsLoader & instance);
	// argument constructor
	ConfigsLoader(int argc, char *argv[], char **envp);

	// returns a map of configurations
	const std::map<std::string, std::string> getConfigs(void);
	
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
	std::vector<std::string> _getConfigsFromFile(std::string pathToFile);
	std::string _pathToFile;
};

#endif // CONFIGS_HPP