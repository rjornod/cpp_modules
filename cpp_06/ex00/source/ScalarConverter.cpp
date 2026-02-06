#include "ScalarConverter.hpp"
#include <regex>

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
static int detectType(std::string)
{ 
    std::regex pattern(R"(^[a-zA-Z]+$)");
}
std::string ScalarConverter::convert(std::string string)
{
    int type = 0;

    type = detectType(string);
}