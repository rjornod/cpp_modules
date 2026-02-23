#include "../include/iter.hpp"
#include <iostream>
#include <string>
#define SIZE 5
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"


/// @brief Prints the string passed into it by reference
/// @param string 
void printStringValue(std::string& string)
{
	std::cout << string << std::endl;
}

void sumIntValue(int& value)
{
	static int sum;
	sum = sum + value;
	std::cout << sum << std::endl;
}


/// @brief Prints the string passed into it by const reference
/// @param string 
void printStringReference(const std::string& string)
{
	std::cout << string << std::endl;
}

void printIntRef(const int& value)
{
	std::cout << value << '\n';
}


int main(void)
{
	int sumArray[] = {2, 2, 2, 2, 2};
	int printArray[] = {1, 2, 3, 4, 5 };
	std::string sArray[SIZE] = {"this", "is", "a", "string", "array"};


	
	std::cout << BLUE << "---- Arguments passed by value ----" << WHITE << std::endl;
	std::cout << GREEN << "        String Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {\"this\", \"is\", \"a\", \"string\", \"array\"}" << WHITE << std::endl;
	::iter(sArray, SIZE, printStringValue);
	std::cout << BLUE << "--------------------------------------" << WHITE << std::endl;
	std::cout << GREEN << "          Int Array Sum" << WHITE << std::endl;
	std::cout << YELLOW << "array = {2, 2, 2, 2, 2}" << WHITE << std::endl;
	::iter(sumArray, SIZE, sumIntValue);

	std::cout << BLUE << "\n---- Arguments passed by reference ----" << WHITE << std::endl;
	std::cout << GREEN << "           String Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {\"this\", \"is\", \"a\", \"string\", \"array\"}" << WHITE << std::endl;
	::iter(sArray, SIZE, printStringReference);
	std::cout << BLUE << "--------------------------------------" << WHITE << std::endl;
	std::cout << GREEN << "             Int Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {1, 2, 3, 4, 5}" << WHITE << std::endl;
	::iter(printArray, SIZE, printIntRef);
}
