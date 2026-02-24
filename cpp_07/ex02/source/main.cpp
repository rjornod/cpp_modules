#include <iostream>
#include <Array.hpp>

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);		// class template, allocates in stack and heap, destructor handles delete
	//int* mirror = new int[MAX_VAL];	// dynamic array, allocated in heap, requires delete []
	//const Array<int> test(7);			// const class template


    std::cout << GREEN << "Creating a class template NUMBERS array with size " << numbers.size() << WHITE <<std::endl;
	srand(time(NULL));
	std::cout << BLUE << "\n.... Assigning the random values to NUMBERS ....\n" << BLUE << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
    }

	Array<int> characters(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
    {
		static int chara = 97;
        characters[i] = chara++;
    }
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << GREEN << "index [" << i << "]\n" << WHITE << "char    = " << static_cast<char>(characters[i]) << std::endl;
	}

	std::cout << BLUE << "\nCOPY ASSIGNMENT TEST numberscpy(numbers)\n" << WHITE << std::endl;
	Array<int> numberscpy(numbers);
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << GREEN << "index [" << i << "]\n" << WHITE << "numbers    = " << numbers[i] << "\nnumberscpy = " << numberscpy[i] << "\n" << std::endl;
	}

/************************************************************************************************************************/
	
	std::cout << BLUE << "DEEP COPY CHECK" << WHITE << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = 1;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << GREEN << "index [" << i << "]\n" << WHITE << "numbers    = " << numbers[i] << "\nnumberscpy = " << numberscpy[i] << "\n" << std::endl;
	}

/***********************************************************************************************************************/
	
	std::cout << RED << "FAILURE CHECKS\n" << WHITE << std::endl;
	std::cout << BLUEBG << " Checking for negative index (-2) on NUMBERS " << BLACKBG << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << WHITE << e.what() << '\n';
    }
	std::cout << "\n" << BLUEBG << " Checking for index above MAX_VAL NUMBERS " << BLACKBG << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr <<  RED << "Error: " << WHITE << e.what() << '\n';
    }
	try
	{

		std::cout << "\n" << BLUEBG << " Accessing an empty array " << BLACKBG << std::endl;
		Array<char> emptychar;
		std::cout << emptychar[0];
	}
	catch (const std::exception& e)
	{
        std::cerr <<  RED << "Error: " << WHITE << e.what() << '\n';
	}

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    return 0;
}