#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
public:
    // Default Constructor
    ScalarConverter();

    // Copy Constructor
    ScalarConverter(const ScalarConverter& other) = delete;

    // Copy Assignment Operator
    ScalarConverter& operator=(const ScalarConverter& other) = delete;

    // Destructor
    ~ScalarConverter();

	static void convert(const std::string& string);

};

#endif
