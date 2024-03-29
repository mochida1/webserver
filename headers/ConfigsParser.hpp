

#pragma once
#ifndef CONFIGSPARSER_HPP
# define CONFIGSPARSER_HPP


#include "DTO_Configs.hpp"

/*
	"Static" class to parse the configs
*/
class ConfigsParser
{
private:
	ConfigsParser(void);
	~ConfigsParser(void);
public:
	static bool parseConfigs(DTO_Configs configs);
};



#endif // CONFIGSPARSER_HPP