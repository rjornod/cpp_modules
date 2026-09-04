#pragma once
#include <iostream>
#include <vector>
#include <deque>


class PmergeMe {
	private:
		std::deque<int> m_dequeValues;
		std::vector<int> m_vectorValues;
		std::vector<int> m_convertedValues;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		void convertExpression(char **argv, int numArguments);
		void handleValue(const std::string& token);
		void initProgram(char **exp, int nArgs);
		void handleVector();
		void handleDeque();
		std::vector<int> applyFordJohnsonVector(std::vector<int> values);
		// std::deque<int> applyFordJohnsonDeque(std::deque<int> values);
};