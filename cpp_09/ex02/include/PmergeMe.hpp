#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
	private:
	std::deque<int> dData;
	std::vector<int> vData;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);
};