#include <iostream>
#include <vector>
#include <deque>


class PmergeMe {
	private:
		std::deque<int> m_dData;
		std::vector<int> m_vData;
		std::vector<int> m_convertedValues;
	public:
		PmergeMe();
		PmergeMe(const std::string& string);
		~PmergeMe();
		PmergeMe operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		void convertExpression(std::string exp);
		void checkForDuplicates(const std::string& exp);
		void isTokenDigit(const std::string& token);
};