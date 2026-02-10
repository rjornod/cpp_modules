#include "ScalarConverter.hpp"
#include <regex>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits.h>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"


int type = 0;

// Default Constructor
ScalarConverter::ScalarConverter() {
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    // std::cout << "ScalarConverter copy constructor called" << std::endl;
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
{	std::regex charPattern(R"(^[\x21-\x2f\x3a-\x7e]$)");	// this range include all printable characters except digits
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

static bool checkDecimalDouble(double dVal)
{
	return (std::floor(dVal) != dVal);
}



static void foundChar(std::string string)
{
	std::cout << "Found a char" << std::endl;
	char car = string[0]; 											// converting from string to char
	std::cout << "char: " << car << std::endl;

	int a = static_cast<int>(car);									// explicit casting from char to int
	std::cout << "int: " << a << std::endl;

	float f = static_cast<float>(car);								// explicit casting from char to floar
	std::cout << "float: " << f << ".0f" << std::endl;

	double b = static_cast<double>(car);							// explicit casting form char to double
	std::cout << "double: " << b << ".0" << std::endl;
}

static void foundInt(std::string string)
{
	std::cout << "Found an int" << std::endl;
	try {															// try catch block to prevent overflow issues

		int intVal = std::stoi(string);								// converting from string to int
		std::cout << "int: " << intVal << std::endl; 				// printing the integer value
		if (checkIfPrintable(intVal)) 								// check if the integer value is printable or not
		{
			char d = static_cast<char>(intVal);						// if it is cast intVal to char and print it
			std::cout << "char: " << d << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;		// if not display an error message
		float f = static_cast<float>(intVal);						// explicit casting from char to float
		std::cout << "float: " << f << ".0f" << std::endl;

		double b = static_cast<double>(intVal);						// explicit casting form char to double
		std::cout << "double: " << b << ".0" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	
}

static void foundDouble(std::string string)
{
	std::cout << "Found a double" << std::endl;
	
	try{
		// convert from string to double
		double doubleVal = std::stod(string);
		if (checkDecimalDouble(doubleVal))								// check if the value contains decimals, if not we add .0 to the output ot
			std::cout << "double: " << doubleVal << std::endl;			// if it does we just print the output as is
		else
			std::cout << "double: " << doubleVal << ".0" << std::endl;	// if not we add a '.0' after the output
		
		// casting to char
		if (checkIfPrintable(doubleVal)) 								// check if the integer value is printable or not
		{
			char d = static_cast<char>(doubleVal);						// if it is, cast intVal to char and print it
			std::cout << "char: " << d << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
		
		//casting to int
		if (doubleVal >= INT_MIN && doubleVal <= INT_MAX)				// check if doubleVal would fit in an integer
		{
			int intVal = static_cast<int>(doubleVal);					// if it does we do a normal static cast and output the value
			std::cout << "int: " << intVal << std::endl;
		}
		else
			std::cout << "int : impossible" << std::endl;				// otherwise we output an impossible message

	}
	catch(std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

static void foundFloat(std::string string)
{
	std::cout << "Found a float" << std::endl;
	std::cout << "double: " << string << std::endl;

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
			foundFloat(string);
			break;
		case DOUBLE:
			foundDouble(string);
			break;
		case INT:
			foundInt(string);
			break;
		default:
			std::cout << RED << "Parameter not recognized. Try with an INT, FLOAT, CHAR or DOUBLE" << WHITE << std::endl;
			break;
	}
}
