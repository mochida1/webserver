/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Configs.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:13:25 by mochida           #+#    #+#             */
/*   Updated: 2024/02/15 20:22:48 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONFIGS_HPP
# define CONFIGS_HPP

#include "IConfigs.hpp"

class Configs : public IConfigs{
public:
	// OCF default constructor
	Configs(void);
	// OCF default destructor
	~Configs(void);
	// OCF copy constructor
	Configs(const Configs & instance);
	// OCF assign operator overload
	Configs & operator=(const Configs & instance);
	// argument constructor
	Configs(int argc, char *argv[]);

	// returns a map of configurations
	std::map<std::string, std::string> getConfigs(std::string pathToFile);
	
protected:
private:
	
	std::map<std::string, std::string> _getRequiredConfigs();
	// bool
};

#endif // CONFIGS_HPP