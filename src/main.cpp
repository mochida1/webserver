

#include "main.hpp"
#include <iostream>

int main (int argc, char *argv[], char **envp){
	std::cout << "ENVP ----------" << std::endl;
	for (int i = 0; envp[i] != NULL; i++){
		std::cout << envp[i] << std::endl;
	}

	(void)(argc);
	(void)(argv);
	
	return 0;
}