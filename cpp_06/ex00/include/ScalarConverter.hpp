#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
public:
    // Default Constructor
    ScalarConverter();

    // Copy Constructor
    ScalarConverter(const ScalarConverter& other);

    // Copy Assignment Operator
    ScalarConverter& operator=(const ScalarConverter& other);

    // Destructor
    ~ScalarConverter();

	static void convert(const std::string& string);

};

#endif
