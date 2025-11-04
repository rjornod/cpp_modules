#include <iostream>
#include <string>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

/** 
 * 
 * 	&stringREF: reference declaration. alternative name for <brain>. does not have its own memory location.
 * printing &stringREF will give us the address of <brain> and
 * printing stringREF will give use the value of <brain> because they are both the same
 * 
 * 	*stringPTR: gets the value at the address <stringPTR> points to
 * returns actual data
 * printing *stringPTR will give use the value of what <stringPTR> is pointing at (same as the value of <brain>)
 * printing stringPTR will give use the address of what it's pointing at (same as the address of <brain>)
 *
 *
 *	Why use references?
 *		-Doesn't use extra memory, it's just an alias for original variable
 *		-No copying, if you pass a varibale by ref you have direct access to the original data. Passing by value creates a full copy
 * 		-Cannot be null, making them safer than pointers
 **/

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout	<< YELLOW
			 	<< "════════ ADDRESSES ════════"
				<< WHITE
				<< std::endl
				<< std::endl;
	std::cout 	<< "Address of string variable <brain>: "
				<< &brain
				<< std::endl; 
	std::cout 	<< "Address of <stringPTR>: "
				<< stringPTR
				<< std::endl;
	std::cout 	<< "Address of <stringREF>: "
				<< &stringREF
				<< std::endl
				<< std::endl;

	std::cout 	<< BLUE
				<< "════════ VALUES ════════"
				<< WHITE
				<< std::endl
				<< std::endl;
	std::cout 	<< "Value of the string <brain>: "
				<< brain
				<< std::endl;
	std::cout 	<< "Value pointed to by <stringPTR>: "
				<< *stringPTR
				<< std::endl;
	std::cout 	<< "Value pointed to by <stringREF>: "
				<< stringREF
				<< std::endl
				<< std::endl;
}

