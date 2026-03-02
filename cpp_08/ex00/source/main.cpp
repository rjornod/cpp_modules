#include <iostream>
#include <easyfind.hpp>
#include <array>
#include <iterator>
#include <vector>

int main(void)
{
    std::vector<int> v = {8, 4, 5, 9};	
	std::array<int, 5> array{1,2,3,4,5};
	
	// ARRAY TEST
	try {
		::easyfind(array, 33);
	}
	catch (std::exception &e)
	{
		    std::cout << "Exception: " << e.what() << std::endl;

	}

	// VECTOR TEST
	try {
		::easyfind(v, 33);
	}
	catch (std::exception &e)
	{
		    std::cout << "Exception: " << e.what() << std::endl;

	}
	
}
