#include "ScalarConverter.hpp"
#include <regex>
#include <string>
#include <iostream>


int type = 0;

// Default Constructor
ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

static int detectType(std::string string)
{	std::regex charPattern(R"(^[a-zA-Z]$)");	// FIX: this range is only for alphabetical characters
	if (std::regex_match(string, charPattern))
		return(CHAR);
	std::regex floatPattern(R"(^[+-]?[0-9]+\.[0-9]+f$)");
	if (std::regex_match(string, floatPattern))
		return(FLOAT);
	std::regex doublePattern(R"(^[+-]?[0-9]+\.[0-9]+$)");
	if (std::regex_match(string, doublePattern))
		return (DOUBLE);
	std::regex intPattern(R"(^[+-]?[0-9]+$)");
	if (std::regex_match(string, intPattern))
	 	return(INT);
	return (-1);
}
//simply checks if the character is printable and returns true or false
static bool checkIfPrintable(char character)
{
	if (character >= 32 && character <= 126)
		return true;
	else
		return false;
}

static void foundChar(std::string string)
{
	std::cout << "Found a char" << std::endl;
	char car = string[0]; 									// converting from string to char
	std::cout << "char: " << car << std::endl;

	int a = static_cast<int>(car);							// explicit casting from char to int
	std::cout << "int: " << a << std::endl;

	float f = static_cast<float>(car);						// explicit casting from char to floar
	std::cout << "float: " << f << ".0f" << std::endl;

	double b = static_cast<double>(car);					// explicit casting form char to double
	std::cout << "double: " << b << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string& string)
{
	int type = detectType(string);
	switch (type)
	{
		case CHAR:
			foundChar(string);
			break;
		case FLOAT:
			std::cout << "Found a float" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Found a double" << std::endl;
			break;
		case INT:
			std::cout << "Found an int" << std::endl;
			{
				int intVal = std::stoi(string);	// FIX: catch stoi overflow	// converting from string to int
				std::cout << "int: " << intVal << std::endl; 				// printing the integer value
				if (checkIfPrintable(intVal)) 								// check if the integer value is printable or not
				{
					char d = static_cast<char>(intVal);						// if it is cast intVal to char and print it
					std::cout << "char: " << d << std::endl;
				}
				else
					std::cout << "char: Non displayable" << std::endl;		// if not display an error message
			}
			break;
		default:
			break;
	}
}
