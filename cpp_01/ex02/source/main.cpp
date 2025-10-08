#include <iostream>
#include <string>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string &stringREF = brain;
	std::string *stringPTR = &brain; 

	std::cout	<< YELLOW
			 	<< "════════ ADDRESSES ════════"
				<< WHITE
				<< std::endl
				<< std::endl;
	std::cout 	<< "Address of string variable: " 
				<< &brain 
				<< std::endl;
	std::cout 	<< "Address of stringPTR: "
				<< stringPTR 
				<< std::endl;
	std::cout 	<< "Address of stringREF: "
				<< &stringREF
				<< std::endl
				<< std::endl;

	std::cout 	<< BLUE
				<< "════════ VALUES ════════"
				<< WHITE
				<< std::endl
				<< std::endl;
	std::cout 	<< "Value of the string brain: "
				<< brain
				<< std::endl;
	std::cout 	<< "Value pointed to by stringPTR: "
				<< *stringPTR
				<< std::endl;
	std::cout 	<< "Value pointed to by stringREF: "
				<< stringREF
				<< std::endl
				<< std::endl;
}

