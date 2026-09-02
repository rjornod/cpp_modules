#include <string>
#include <exception>
#include <limits>
#include <algorithm> // std::find
#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {
}


PmergeMe::~PmergeMe() {

}

PmergeMe PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
	m_dequeValues = other.m_dequeValues;
	m_vectorValues = other.m_vectorValues;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	m_dequeValues = other.m_dequeValues;
	m_vectorValues = other.m_vectorValues;
}

void PmergeMe::initProgram(char *string, int nArgs) {
	std::string exp = string;
	convertExpression(exp, nArgs);
}

void PmergeMe::convertExpression(std::string exp, int nArgs) {
	size_t end;
	std::cout << nArgs << "\n";
	if (exp.empty())
		throw std::runtime_error("No arguments provided");

	while (!exp.empty()) {
		end = exp.find_first_of(" \t\n\r\f\v");
		std::string temp = exp.substr(0, end);
		exp.erase(0, exp.find_first_not_of(" \t\n\r\f\v", end));
		handleValue(temp);
		std::cout << "m_convertedValues: " << m_convertedValues.back() << "\n";
			std::cout << "m_dequeValues: " << m_dequeValues.back() << "\n";
				std::cout << "m_vectorValues: " << m_vectorValues.back() << "\n";
		if (end == std::string::npos)
			exp.clear();
	}
}

void PmergeMe::handleValue(const std::string& token) {
	size_t i = 0;
	while (i < token.size()) {
		if (!std::isdigit(token[i])) {
			throw std::runtime_error("Error: invalid value\n");
		}
		i++;
	}
	try {
		std::string tempString = token;
		unsigned long temp = std::stoul(tempString.c_str());
		if ( std::numeric_limits<int>::max() < temp ) 
			throw std::out_of_range("Number too big");
		if (std::find(m_convertedValues.begin(), m_convertedValues.end(), temp) != m_convertedValues.end())			// duplicate check
			throw std::runtime_error("Duplicate number found");
		m_convertedValues.push_back(temp);
		m_dequeValues.push_back(temp);
		m_vectorValues.push_back(temp);
	}
	catch (const std::out_of_range &e) {
		throw std::out_of_range(e.what());
	}
}
