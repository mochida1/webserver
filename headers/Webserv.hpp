/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:08:02 by mochida           #+#    #+#             */
/*   Updated: 2024/02/14 23:23:39 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <string>

class Webserv{
public:
	Webserv(void);
	~Webserv(void);
	Webserv(int argc, char *argv[]);
	int init(int argc, char *argv[]);
protected:
private:
};

#endif //WEBSERV_HPP