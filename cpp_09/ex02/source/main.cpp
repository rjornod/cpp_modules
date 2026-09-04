#include "PmergeMe.hpp"

int main(int argc, char** argv) {

	try {
		if (argc < 2)
			throw std::runtime_error("Invalid argument amount. Usage ./PmergeMe \"3 1 10 4 2 \"");
		PmergeMe pmergeMe;
		pmergeMe.initProgram(argv, argc);
	}
		catch(const std::exception& e) {
			std::cerr << e.what() << "\n";
		}

}