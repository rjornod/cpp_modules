#include <iostream>
#include <string>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string& stringREF = brain;
	std::string* stringPTR = &brain; 

	std::cout 	<< "Address of string variable: " 
				<< &brain 
				<< std::endl;
	std::cout 	<< "Address of stringPTR: "
				<< &stringPTR 
				<< std::endl;
	std::cout 	<< "Address of stringREF: "
				<< &stringREF
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
				<< std::endl;
}

