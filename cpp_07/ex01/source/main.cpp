#include "../include/iter.hpp"
#include <iostream>
#include <string>

void printString(std::string string)
{
	std::cout << string << std::endl;
}
void printInt(int value)
{
	std::cout << value << std::endl;
}

int main(void)
{
	int iArray[] = {1, 2, 3, 4, 5};
	std::string sArray[2] = {"hello","test"};
	::iter(sArray, 2, printString);
	::iter(iArray, 5, printInt);
}
