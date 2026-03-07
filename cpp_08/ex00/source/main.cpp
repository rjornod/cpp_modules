#include <iostream>
#include <easyfind.hpp>
#include <array>
#include <iterator>
#include <vector>
#include <deque>

int main(void)
{
	std::array<int, 5> array{1, 2, 2, 4, 3};
    std::vector<int> vector = {8, 4, 5, 2};	
	std::deque<int> deque = {7, 5, 16, 8};

	// ARRAY TEST
	try {
		::easyfind(array, 3);
	}
	catch (std::exception &e)
	{
		    std::cout << "Exception: " << e.what() << std::endl;

	}

	// VECTOR TEST
	try {
		::easyfind(vector, 8);
	}
	catch (std::exception &e)
	{
		    std::cout << "Exception: " << e.what() << std::endl;

	}

	// DEQUE TEST
	try {
		::easyfind(deque, 8);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
