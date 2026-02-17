#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
	private:
		// Default Constructor
		ScalarConverter() = default;

		// Copy Constructor
		ScalarConverter(const ScalarConverter& other) = delete;

		// Copy Assignment Operator
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		// Destructor
		~ScalarConverter() = default;

	public:
		static void convert(const std::string& string);

};

#endif
