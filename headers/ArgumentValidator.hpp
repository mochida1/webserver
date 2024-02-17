
#include <string>
#include <exception>
#include <stdexcept>
#include <set>
#include <vector>
#include <filesystem>
#include <unistd.h>
#include <cerrno>
#include <cstring>

//ideally those should be inside inherited class to help with dependency inversion
#include "Errors_webserv.hpp"
#include "Constraints_webserv.hpp"

class ArgumentValidator {
public:
	static void	validateArguments(int argc, char *argv[]);
	static bool checkEnvs(char **envp);

	// Excpetion-----------
	class ArgumentValidatorException : public std::exception {
	public:
		// Constructor with a custom error message
		ArgumentValidatorException(const std::string& message) : errorMessage(message) {}

		// Override the what() function to provide the error message
		const char* what() const throw(){
			return errorMessage.c_str();
		}
		~ArgumentValidatorException() throw() {}
	private:
		std::string errorMessage;
	};
	//---------------------
protected:
private:
	// OCF default constructor
	ArgumentValidator(void);
	// OCF default destructor
	~ArgumentValidator(void);
	// OCF copy constructor
	ArgumentValidator(const ArgumentValidator & instance);
	// OCF assign operator overload
	ArgumentValidator & operator=(const ArgumentValidator & instance);
	// argument constructor
	ArgumentValidator(int argc, char *argv[], char **envp);
	//--------------------------------------------------------

};