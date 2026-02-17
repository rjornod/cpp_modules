#include "../include/ScalarConverter.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << RED << "Too many parameters" << WHITE <<std::endl;
		return (1);
	}
	if (argc != 2)
	{
		std::cout << RED << "No parameter provided" << WHITE << std::endl;
		return (1);
	}
	
	// ScalarConverter test;

	ScalarConverter::convert(argv[1]);
	
	return (0);
}