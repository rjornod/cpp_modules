#pragma once
#include <iostream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"

template<typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;

}

template<typename T>
T min(const T& value1, const T& value2)
{
	if (value1 < value2)
		return (value1);
	else
		return (value2);
	if (value1 == value2)
		return (value2);		
}

template<typename T>
T max(const T& value1, const T& value2)
{
	if (value1 < value2)
		return (value2);
	else
		return (value1);
	if (value1 == value2)
		return (value2);		
}
