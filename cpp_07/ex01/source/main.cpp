#include "../include/iter.hpp"
#include <iostream>
#include <string>
#define SIZE 5
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"



void printStringRef(std::string& string)
{
	std::cout << string << std::endl;
}

void sumIntRef(int& value)
{
	static int sum;
	sum = sum + value;
	std::cout << sum << std::endl;
}


void printStringConstRef(const std::string& string)
{
	std::cout << string << std::endl;
}

void printIntConstRef(const int& value)
{
	std::cout << value << '\n';
}


int main(void)
{
	// ARRAYS
	int sumArray[] = {2, 2, 2, 2, 2};
	const int printArray[] = {1, 2, 3, 4, 5 };
	std::string sArray[SIZE] = {"this", "is", "a", "string", "array"};


	// NON CONST REFERENCES
	std::cout << BLUE << "---- Arguments passed by non const reference ----" << WHITE << std::endl;
	std::cout << GREEN << "        String Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {\"this\", \"is\", \"a\", \"string\", \"array\"}" << WHITE << std::endl;
	::iter(sArray, SIZE, printStringRef);
	std::cout << BLUE << "--------------------------------------" << WHITE << std::endl;
	std::cout << GREEN << "          Int Array Sum" << WHITE << std::endl;
	std::cout << YELLOW << "array = {2, 2, 2, 2, 2}" << WHITE << std::endl;
	::iter(sumArray, SIZE, sumIntRef);


	// CONST REFERENCES
	std::cout << BLUE << "\n---- Arguments passed by const reference ----" << WHITE << std::endl;
	std::cout << GREEN << "           String Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {\"this\", \"is\", \"a\", \"string\", \"array\"}" << WHITE << std::endl;
	::iter(sArray, SIZE, printStringConstRef);
	std::cout << BLUE << "--------------------------------------" << WHITE << std::endl;
	std::cout << GREEN << "             Int Array Print" << WHITE << std::endl;
	std::cout << YELLOW << "array = {1, 2, 3, 4, 5}" << WHITE << std::endl;
	::iter(printArray, SIZE, printIntConstRef);
}
