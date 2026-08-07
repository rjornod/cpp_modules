#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <exception>

BitcoinExchange::BitcoinExchange() {
	std::string filePath = "data.csv";
	try {
		loadData(filePath);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
	: m_dataBase(other.m_dataBase) {}
	
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		m_dataBase = other.m_dataBase;
	}
	return *this;
}

void BitcoinExchange::loadData(const std::string& filePath) {
	std::string buffer;
	std::fstream file(filePath);
	// check if file exists and can be opened
	if (!file) {
		throw std::runtime_error("Can't open specified database.");
	}
	// checks if file is empty
	bool isEmpty = file.peek() == EOF;
	if (isEmpty)
		throw std::runtime_error("Config file is empty. Make sure you use a valid config file");

	while (std::getline(file, buffer)) {
		unsigned long i = 0;
		while (i < buffer.size()) {
			std::cout << buffer[i];
			i++;
		}
	}
}




