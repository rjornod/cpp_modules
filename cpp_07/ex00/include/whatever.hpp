#pragma once
#include <iostream>

/*
	-values should be passed by reference so as to have modifications take place
 	-use references when you need to modify the original, or when you want to avoid
expensive copying with large objects 
*/
template<typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;

}

template<typename T>
T min(T value1, T value2)
{
	if (value1 < value2)
		return (value1);
	else
		return (value2);
	if (value1 == value2)
		return (value2);		
}

template<typename T>
T max(T value1, T value2)
{
	if (value1 < value2)
		return (value2);
	else
		return (value1);
	if (value1 == value2)
		return (value2);		
}
