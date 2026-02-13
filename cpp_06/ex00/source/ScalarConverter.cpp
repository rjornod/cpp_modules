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
#define IMPOSSIBLE -1
#define NON_PRINT 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDO 5

// Default Constructor
ScalarConverter::ScalarConverter() {
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter() {
    // std::cout << "ScalarConverter destructor called" << std::endl;
}

static void foundPseudoLiteral(std::string string)
{

	std::cout << "int: impossible" << std::endl;
	std::cout << "char: impossble" << std::endl;
	if (string == "nan" || string == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}

	if (string == "+inf" || string == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	if (string == "-inf" || string == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static int detectType(std::string string)
{	std::regex charPattern(R"(^[\x21-\x2f\x3a-\x7e]$)");	// this range include all printable characters except digits
	if (std::regex_match(string, charPattern))
		return(CHAR);
	std::regex floatPattern(R"(^[+-]?[0-9]+\.[0-9]+f$)");	// this range matches floats by checking for a '.' in the middle and an 'f' at the end
	if (std::regex_match(string, floatPattern))
		return(FLOAT);
	std::regex doublePattern(R"(^[+-]?[0-9]+\.[0-9]+$)"); 	// this range maches a double by checking for a dot in the middle of digits
	if (std::regex_match(string, doublePattern))
		return (DOUBLE);
	std::regex intPattern(R"(^[+-]?[0-9]+$)");				// this range matches only digits
	if (std::regex_match(string, intPattern))
	 	return(INT);
	if (string == "nan" || string == "nanf" || string == "-inf" || string == "+inf" || string == "-inff" || string == "+inff") // if nothing matches so far we check for pseudoliterals
		return (PSEUDO);
	return (-1);
}

//simply checks if the character is printable and returns true or false
static int checkIfPrintable(int character)
{
	if (character < 0 || character > 127)
		return (IMPOSSIBLE);
	if (character < 32 || character == 127)
		return (NON_PRINT);
	else
		return 1;
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
		switch (checkIfPrintable(intVal))
		{
			case IMPOSSIBLE:
				std::cout << "char: impossible" << std::endl;
				break;
			case NON_PRINT:
				std::cout << "char: Non displayable" << std::endl;		// if not display an error message
				break;
			default:
				char d = static_cast<char>(intVal);						// if it is cast intVal to char and print it
				std::cout << "char: " << d << std::endl;
				break;
		}
		
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

		//casting to int
		if (doubleVal >= INT_MIN && doubleVal <= INT_MAX)				// check if doubleVal would fit in an integer
		{
			int intVal = static_cast<int>(doubleVal);					// if it does we do a normal static cast and output the value
			std::cout << "int: " << intVal << std::endl;
		}
		else
			std::cout << "int : impossible" << std::endl;				// otherwise we output an impossible message

		// casting to char
		switch (checkIfPrintable(doubleVal))
		{
		case IMPOSSIBLE:
			std::cout << "char: impossible" << std::endl;
			break;
		case NON_PRINT:
			std::cout << "char: Non displayable" << std::endl;			// if not display an error message
			break;
		default:
			char d = static_cast<char>(doubleVal);						// if it is cast intVal to char and print it
			std::cout << "char: " << d << std::endl;
			break;
		}

		float floatVal = static_cast<float>(doubleVal);

		std::cout << std::fixed;

		if (checkDecimalDouble(doubleVal))								// check if the value contains decimals, if not we add .0 to the output ot
			{
				std::cout << std::setprecision(4) << "float: " << floatVal << "f" << std::endl;	// FIX: need to print f and/or .0 after number
				std::cout << std::setprecision(4) << "double: " << doubleVal << std::endl;		// if it does we just print the output as is
			}
		else
		{
			
			std::cout << std::setprecision(1) << "float: " << floatVal << "f" << std::endl;
			std::cout << std::setprecision(1) << "double: " << doubleVal << std::endl;			// if not we add a '.0' after the output
		}
	}
	catch(std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
}

static void foundFloat(std::string string)
{
	

	std::cout << "Found a float" << std::endl;
	try {
			double doubleVal = std::stod(string);

			//casting to int
			if (doubleVal >= INT_MIN && doubleVal <= INT_MAX)			// check if doubleVal would fit in an integer
			{
				int intVal = static_cast<int>(doubleVal);					// if it does we do a normal static cast and output the value
				std::cout << "int: " << intVal << std::endl;
			}
			else
				std::cout << "int : impossible" << std::endl;				// otherwise we output an impossible message

			switch (checkIfPrintable(doubleVal))
			{
			case IMPOSSIBLE:
				std::cout << "char: impossible" << std::endl;
				break;
			case NON_PRINT:
				std::cout << "char: Non displayable" << std::endl;			// if not display an error message
				break;
			default:
				char d = static_cast<char>(doubleVal);						// if it is cast intVal to char and print it
				std::cout << "char: " << d << std::endl;
				break;
			}

			
			float floatVal = static_cast<float>(doubleVal);

			std::cout << std::fixed;

			doubleVal = static_cast<double>(floatVal);
			if (checkDecimalDouble(doubleVal))								// check if the value contains decimals, if not we add .0 to the output ot
			{
				std::cout << std::setprecision(4) << "float: " << floatVal << "f" << std::endl;	// FIX: need to print f and/or .0 after number
				std::cout << std::setprecision(4) << "double: " << doubleVal << std::endl;		// if it does we just print the output as is
			}
			else
			{
				std::cout << std::setprecision(1) << "float: " << floatVal << "f" << std::endl;
				std::cout << std::setprecision(1) << "double: " << doubleVal << std::endl;			// if not we add a '.0' after the output
			}
	}
	catch (std::exception &e)
	{
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	

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
		case PSEUDO:
			foundPseudoLiteral(string);
			break;
		default:
			std::cout << RED << "Parameter not recognized. Try with an INT, FLOAT, CHAR or DOUBLE" << WHITE << std::endl;
			break;
	}
}
