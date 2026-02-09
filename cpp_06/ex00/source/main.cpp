#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "No value provided" << std::endl;
		return (1);
	}
	ScalarConverter test;

	test.convert(argv[1]);
}