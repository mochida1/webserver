/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IConfigs.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:31:59 by mochida           #+#    #+#             */
/*   Updated: 2024/02/15 18:01:29 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>

class IConfigs{
public:
	// OCF default constructor
	IConfigs(void);
	// OCF default destructor
	~IConfigs(void);
	// OCF copy constructor
	IConfigs(const IConfigs & instance);
	// OCF assign operator overload
	IConfigs & operator=(const IConfigs & instance);
	// argument constructor
	IConfigs(int argc, char *argv[]);

	// returns a map of configurations
	virtual std::map<std::string, std::string> getConfigs(std::string pathToFile) = 0;
	
protected:
private:
};