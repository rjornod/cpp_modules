#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <bits/stdc++.h>
#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <chrono>
#define RED "\e[1;31m"
#define RESET "\033[0m"

BitcoinExchange::BitcoinExchange(char* path) {
	std::ifstream file("data.csv");
	loadData(file);
	try {
		// std::ifstream inputFile()
		validateInputFile(path);
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

void BitcoinExchange::validateInputFile(const std::string& filePath) {
	std::ifstream file(filePath);
	std::string		buffer;
	int						j = 0;
	// check if file exists and can be opened
	if (!file) {
		throw std::runtime_error("Can't open specified input file.");
	}
	// checks if file is empty
	bool isEmpty = file.peek() == EOF;
	if (isEmpty)
		throw std::runtime_error("Input file is empty. Make sure you use a valid input file");
	while (std::getline(file, buffer)) {
		// int start = 0;
		// unsigned long i = 0;
		if (j++ == 0)
			continue;
		std::size_t separator = buffer.find('|');
		if (separator == std::string::npos) {
			std::cout << RED << "ERROR: bad input => " << RESET << buffer << "\n";
		}
		std::string date = buffer.substr(0, separator);
		std::string valueString = buffer.substr(separator + 1);
		
		double value = std::stod(valueString);
		if (!isDateValid(date))
			std::cout << RED << "ERROR: bad input => " << RESET << date << ", " << value << "\n";
		else if (!isValueValid(value)) 
			std::cout << "\n";
		else {
			
			std::map<std::string, double>::iterator closestDate = findClosestDate(date);
			// std::cout << "closest date to " << date << ": " << closestDate->first << "\n";
			double result = applyMultiplication(closestDate ,value);
			std::cout <<  date << ", " << result << "\n";
		}
	}
}

double BitcoinExchange::applyMultiplication(std::map<std::string, double>::iterator closestDate, double value) {
	double result = closestDate->second * value;
	return result;
}

std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(const std::string& date) {
	// for (auto it = m_dataBase.begin(); it != m_dataBase.end(); it++) {
	// 	if(it->first == date)
	// 		return it;
	// }
	auto it = m_dataBase.lower_bound(date);
	if (it != m_dataBase.end() && it->first == date)
		return it;
	if (it == m_dataBase.begin())
		return m_dataBase.end();
	return --it;
}

bool BitcoinExchange::isValueValid(double value) {
	if (value < 0){
		std::cout << RED << "ERROR: not a positive number" << RESET;
		return false;
	}
	else if (value > 1000) {
		std::cout << RED <<  "ERROR: too large a number" << RESET;
		return false;
	}
	return true;
}

std::chrono::year_month_day BitcoinExchange::convertDate(std::string string) {
	int year;
	unsigned int month;
	unsigned int day;
	char dash1;
	char dash2;

	std::istringstream stream(string);
	stream >> year >> dash1 >> month >> dash2 >> day; 
	// ||
	// 		dash1 != '-' ||
	// 		dash2 != '-' ||
	// 		!stream.eof())
	// 	return std::chrono::year_month_day{}; // return a default constructed date which will be read as invalid by date.ok()
	// constructs chrono::year_month_day object with the values we got above
	const std::chrono::year_month_day date {
        std::chrono::year{year},
        std::chrono::month{month},
        std::chrono::day{day}
	};
	return date;
}

bool BitcoinExchange::isDateValid(const std::string& string) {
	std::chrono::year_month_day date = convertDate(string);
	// std::cout << "Year: " << static_cast<int>(date.year())
  //             << ", Month: " << static_cast<unsigned>(date.month())
  //             << ", Day: " << static_cast<unsigned>(date.day()) << '\n';
	return date.ok();
}

void BitcoinExchange::loadData(std::ifstream& file) {
	std::string	buffer;
	int 				j = 0;
	while (std::getline(file, buffer)) {
		int start = 0;
		int i = 0;
		if (j++ == 0)
			continue;
		while (buffer[i] != ',')
			i++;
		std::string date = buffer.substr(start, i);
		start = i + 1;
		double value = std::stod(buffer.substr(start));
		// if (!isDateValid(date)) {
		// 	std::cout << "ERROR: bad input => " << date << ", " << value << "\n";
			// return;
		// }
		m_dataBase.emplace(date, value);
	}
	// for (auto it = m_dataBase.begin(); it != m_dataBase.end(); it++) {
	// 	std::cout << std::fixed << std::setprecision(2) << it->first<< ", " << it->second << "\n";
	// }
}




