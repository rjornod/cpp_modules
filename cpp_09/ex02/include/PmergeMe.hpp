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
		PmergeMe operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		void convertExpression(std::string exp, int numArguments);
		void handleValue(const std::string& token);
		void initProgram(char *exp, int nArgs);
};