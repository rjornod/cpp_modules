#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
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
