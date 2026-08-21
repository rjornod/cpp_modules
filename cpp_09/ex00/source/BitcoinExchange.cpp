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
	if (!file) {																																									// check if file exists and can be opened
		throw std::runtime_error("Can't open specified input file.");
	}
	bool isEmpty = file.peek() == EOF;																														// checks if file is empty
	if (isEmpty)
		throw std::runtime_error("Input file is empty. Make sure you use a valid input file");
	while (std::getline(file, buffer)) {
		if (j++ == 0)
			continue;
		if (buffer.empty() || isStringNotWhiteSpace(buffer))
			continue;
		std::size_t separator = buffer.find('|');
		if (separator == std::string::npos) {																												// check if there is not separator
			std::cout << RED << "ERROR: bad input => " << RESET << buffer << "\n";
			continue;
		}
		if (buffer.find_last_of('|') != separator) {																								// check for multiple separators
			std::cout << RED << "ERROR: bad input => " << RESET << buffer << "\n";
			continue;
		}
		size_t start = buffer.find_first_not_of(" \t\n\r\f\v");																			// skip leading whitespaces
		std::string date = buffer.substr(start, separator);
		size_t end = date.find_first_of(" \t\n\r\f\v");																							//skip trailing whitespaces
		date = date.substr(0, end);
		std::string valueString = buffer.substr(separator + 1);
		if (date.empty() || valueString.empty() || isStringNotWhiteSpace(date) || isStringNotWhiteSpace(valueString))	{				// check if both parameters are present
			std::cout << RED << "ERROR: Missing parameter\n" << RESET;
			continue;
		}
		if (!isValueDigit(valueString)) {																														// check if the value is a positive float
			std::cout << RED << "ERROR: Value not valid\n" << RESET;
			continue;
		}
		double value = std::stod(valueString);
		if (!isDateValid(date))
			std::cout << RED << "ERROR: bad input => " << RESET << date << ", " << value << "\n";
		else if (!isValueValid(value))
			std::cout << "\n";
		else {
			std::map<std::string, double>::iterator closestDate = findClosestDate(date);
			// date picked should be either the exact one or the closest lowest one
			// this checks if the date is before the first date in the data.csv file
			// in that case since there would be no date equal or lower it should thrown an error
			if (closestDate == m_dataBase.end()) {
   			std::cout << RED << "ERROR: no exchange rate available for this date"
              		<< RESET << "\n";
    		continue;
			}
			double result = applyMultiplication(closestDate ,value);
			std::cout <<  date << ", " << result << "\n";
		}
	}
}

/**
 * Checks if string passed only contains white spaces
 */
bool BitcoinExchange::isStringNotWhiteSpace(const std::string& string) {
	for (size_t i = 0; i < string.size(); i++) {
		if (!std::isspace(static_cast<unsigned char>(string[i]))) {
			return false;
		}
	}
	return true;
}

double BitcoinExchange::applyMultiplication(std::map<std::string, double>::iterator closestDate, double value) {
	double result = closestDate->second * value;
	return result;
}

/**
 * Finds the closest date by using lower_bound. That returns the first element that is not lower than the key
 * So to return the next closest lowest date, it needs to return --it
 * lower_bound on 2011-02-04 on give us an iterator to 2011-02-05. --it would then get us 2011-02-03
 */
std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(const std::string& date) {
	auto it = m_dataBase.lower_bound(date);
	if (it != m_dataBase.end() && it->first == date)
		return it;
	if (it == m_dataBase.begin())
		return m_dataBase.end();
	return --it;
}

/**
 * Checks if value is a positive float
 */
bool BitcoinExchange::isValueDigit(const std::string& string) {
	int dotCount = 0;
	size_t j = 0;
	while (std::isspace(string[j]))
		j++;
	for (size_t i = j; i < string.size(); i++) {
		if (string[i] == '.') {
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		else if (!std::isdigit(static_cast<unsigned char>(string[i])))
			return false;
	}
	return true;
}

/**
 * Checks if the value is between 0 and 1000
 */
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

/**
 * Converts the date from a string into a std::chrono::year_month_day type
 */
std::chrono::year_month_day BitcoinExchange::convertDate(std::string string) {
	int year;
	unsigned int month;
	unsigned int day;
	char dash1;
	char dash2;

	std::istringstream stream(string);
	if (!(stream >> year >> dash1 >> month >> dash2 >> day) ||
			dash1 != '-' ||
			dash2 != '-' ||
			!stream.eof())
		return std::chrono::year_month_day{}; // return a default constructed date which will be read as invalid by date.ok()
	// constructs chrono::year_month_day object with the values we got above
	const std::chrono::year_month_day date {
        std::chrono::year{year},
        std::chrono::month{month},
        std::chrono::day{day}
	};
	return date;
}

/**
 * Checks if the converted date is valid or not with date.ok()
 */
bool BitcoinExchange::isDateValid(const std::string& string) {
	std::chrono::year_month_day date = convertDate(string);
	// std::cout << "Year: " << static_cast<int>(date.year())
  //             << ", Month: " << static_cast<unsigned>(date.month())
  //             << ", Day: " << static_cast<unsigned>(date.day()) << '\n';
	return date.ok();
}

/**
 * Takes the data from the opened file and stores it into the m_dataBase map
 */
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
		m_dataBase.emplace(date, value);
	}
}
