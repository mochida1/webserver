

#pragma once
#ifndef DTO_CONFIGS_HPP
# define DTO_CONFIGS_HPP

#include <vector>
#include <map>
#include <string>

struct DTO_Configs
{
	std::string name;
	std::map< std::string, std::vector<std::string> > property;
	std::vector<DTO_Configs> context;
};

#endif // DTO_CONFIGS_HPP