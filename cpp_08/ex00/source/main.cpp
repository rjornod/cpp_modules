#include <iostream>
#include <easyfind.hpp>
#include <array>
#include <iterator>
#include <vector>

int main(void)
{
    std::vector<int> v = {8, 4, 5, 2};	
	std::array<int, 5> array{1,2,2,4,3};
	
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
		::easyfind(v, 9);
	}
	catch (std::exception &e)
	{
		    std::cout << "Exception: " << e.what() << std::endl;

	}
	
}
