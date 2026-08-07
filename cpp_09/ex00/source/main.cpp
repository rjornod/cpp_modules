#include <iostream>
#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)	{
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <file_name>" << std::endl;
	}
	BitcoinExchange exchange;
}