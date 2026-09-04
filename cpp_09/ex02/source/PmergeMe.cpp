#include <string>
#include <exception>
#include <limits>
#include <algorithm> // std::find
#include <string>
#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {
}


PmergeMe::~PmergeMe() {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
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

void PmergeMe::initProgram(char **string, int nArgs) {
	// std::string exp = string;
	convertExpression(string, nArgs);
	// m_dequeValues = applyFordJohnsonDeque(m_dequeValues);
	std::cout << "applying fordjohnson\n";
	m_vectorValues = applyFordJohnsonVector(m_vectorValues);
	std::cout << "Before: ";
	for (size_t i = 0; i < m_convertedValues.size(); i++) {
		std::cout << m_convertedValues[i] << " ";
	}
	std::cout << "\nAfter: ";
	for (size_t i = 0; i < m_vectorValues.size(); i++) {
		std::cout << m_vectorValues[i] << " ";
	}
	std::cout << "\n";
}

void PmergeMe::convertExpression(char** exp, int nArgs) {
	int i = 1;
	while (i < nArgs) {
		std::string arg = exp[i];
		handleValue(arg);
		// std::cout << "m_convertedValues: " << m_convertedValues.back() << "\n";
		// std::cout << "m_dequeValues: " << m_dequeValues.back() << "\n";
		// std::cout << "m_vectorValues: " << m_vectorValues.back() << "\n";
		i++;
	}
}

void PmergeMe::handleValue(const std::string& token) {
	size_t i = 0;
	while (i < token.size()) {
		if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
			throw std::runtime_error("Error: invalid value\n" + token);
		}
		i++;
	}
	try {
		unsigned long temp = std::stoul(token.c_str());
		if ( std::numeric_limits<int>::max() < temp ) 
			throw std::out_of_range("Number too big");
		if (std::find(m_convertedValues.begin(), m_convertedValues.end(), temp) != m_convertedValues.end())			// duplicate check
			throw std::runtime_error("Duplicate number found");
		if (temp == 0)
			throw std::out_of_range("Only positive integers allowed. 0 is invalid");
		m_convertedValues.push_back(temp);
		m_dequeValues.push_back(temp);
		m_vectorValues.push_back(temp);
	}
	catch (const std::out_of_range &e) {
		throw std::out_of_range(e.what());
	}
}

static void printVector(std::vector<int> vector, const std::string& name) {
	std::cout << name << ": \n";
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << vector[i]<< " "; 
	}
	std::cout << "\n";
}

std::vector<int> PmergeMe::applyFordJohnsonVector(std::vector<int> values) {
	if (values.size() < 2)
		return values;
	std::vector<std::pair<int,int>> vectorPairs;
	size_t i = 0;
	std::cout << "starting loop\n";
	while (i + 1 < values.size()) {
		std::cout << "loop " << i <<"\n";
		int first = m_vectorValues[i];
		int second = m_vectorValues[i + 1];
		if (first < second)
			std::swap(first, second);
		vectorPairs.emplace_back(first, second);
		i += 2;	
	}
	std::vector<int> winners;
	for (size_t i = 0; i < vectorPairs.size(); i++) {
		winners.emplace_back(vectorPairs[i].first); 
	}
	std::vector<int> sortedWinners = applyFordJohnsonVector(winners);
	printVector(winners, "winners");
	return sortedWinners;
}


// std::deque<int> PmergeMe::applyFordJohnsonDeque(std::deque<int> values) {
// 	std::deque<std::pair<int,int>>	dequePairs;
// 	return values;

// }