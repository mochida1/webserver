
#pragma once
#ifndef CONFIGS_HPP
# define CONFIGS_HPP

#include "DTO_Configs.hpp"
#include "ConfigsLoader.hpp"
#include "ConfigsParser.hpp"
#include <iostream>

/*
	Wrapper class to things that encapsulates configuration data loading, parsing and retrieving.
*/

class Configs
{
private:
	DTO_Configs _dto;
	Configs(void);
public:
	Configs(int argc, char *argv[], char **envp);
	DTO_Configs getContextByName(std::string pName);
	void printDTO(void);
	~Configs();
};


class ConfigsTest : public Configs
{
private:
	/* data */
public:
	ConfigsTest(DTO_Configs dto);
	~ConfigsTest(void);
};




#endif // CONFIGS_HPP