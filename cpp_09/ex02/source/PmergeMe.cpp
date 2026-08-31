#include <string>
#include <exception>
#include <limits>
#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const std::string& string) {
	std::cout << "Expression: " << string << "\n";
	checkForDuplicates(string);
	convertExpression(string);
}

PmergeMe::~PmergeMe() {

}

PmergeMe PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
	m_dData = other.m_dData;
	m_vData = other.m_vData;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	m_dData = other.m_dData;
	m_vData = other.m_vData;
}

void PmergeMe::convertExpression(std::string exp) {
	std::string temp; 
	size_t end;

	while (!exp.empty()) {
	end = exp.find_first_of(" \t\n\r\f\v");
	temp = exp.substr(0, end);
	exp.erase(0, exp.find_first_not_of(" \t\n\r\f\v", end));
	isTokenDigit(temp);
	int token = std::stoll(temp);
	m_convertedValues.push_back(token);
	std::cout << "m_convertedValues: " << m_convertedValues.back() << "\n";
	if (end == std::string::npos)
		exp.clear();
}
}

void PmergeMe::checkForDuplicates(const std::string &exp)
{
	std::cout << exp << "   test\n";
	// throw std::runtime_error("There are duplicate values in the expression");
}

void PmergeMe::isTokenDigit(const std::string& token) {
	size_t i = 0;
	while (i < token.size()) {
		if (!std::isdigit(token[i])) {
			throw std::runtime_error("Error: value not a digit: " + token);
		}
		i++;
	}
	try {
		std::string tempString = token;
		unsigned long temp = std::stoul(tempString.c_str());
		if ( std::numeric_limits<int>::max() < temp ) 
			throw std::out_of_range("Number too big");
	}
	catch (const std::out_of_range &e) {
		throw std::out_of_range("Number too big");
	}
}
