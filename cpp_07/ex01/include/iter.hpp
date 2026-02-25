#pragma once
#include <iostream>

// this function template accepts non const arrays
// using typname Function allows the template to accept any callable type
template<typename T, typename Function> 			
void iter(T *array, const size_t size, Function f)
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

// this function template accepts const arrays
template<typename T, typename Function>
void iter(const T *array, const size_t size, Function f)
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}