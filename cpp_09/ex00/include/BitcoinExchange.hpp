#pragma once
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

class BitcoinExchange {
	private:
		std::map<std::string, double> m_dataBase;
	public:
		BitcoinExchange(char* path);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange& other);
		
		void 				loadData(std::ifstream& file);
		void 				validateInputFile(const std::string& file);
		bool 				isDateValid(const std::string& date);
		bool 				isValueValid(double value);
		bool				isValueDigit(const std::string& digit);
		bool				isStringNotWhiteSpace(const std::string& string);
		double			applyMultiplication(std::map<std::string, double>::iterator closestDate, double value);
		std::map<std::string, double>::iterator	findClosestDate(const std::string& date);
		std::chrono::year_month_day convertDate(std::string date);
};