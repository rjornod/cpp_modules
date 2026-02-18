#pragma once
#include <iostream>

template<typename T, typename Function>
void iter(T *array, const size_t size, Function f)
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}