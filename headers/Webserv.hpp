

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