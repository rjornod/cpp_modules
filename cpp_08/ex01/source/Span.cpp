#include <Span.hpp>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <numeric>

Span::Span(unsigned int N) : _max(N)
{

}

Span::~Span()
{}

Span::Span(const Span& other) : _max(other._max), _values(other._values)
{

}

void Span::spanFill(unsigned int amount)
{
	if (amount <= _max && (_values.size() + amount) <= _max) 			// check if amount to fill the span with would fit in _max
	{
		std::generate_n(std::back_inserter(_values), amount, [](){ return rand();});
	}
	else  																// if not throw an exception
	{
		throw std::length_error("Span doesn't have enough space for all those elements");
	}
	std::cout << "Amount of values added: " << _values.size() << std::endl;
}

void Span::addNumber(unsigned int N)
{
	if (N < 0)
		throw std::invalid_argument("Not a valid number");
	if (_values.size() < _max)									// check if container is already full	
		_values.push_back(N);									// if not add the value
	else
		throw std::length_error("Container is already full");	//if its full, throw an error
	for (int value : _values)  									//print all the values added
	{
    	std::cout << value << " ";
	}
	std::cout << std::endl;
}

unsigned int Span::shortestSpan()
{
	if (_values.size() <= 1)
		throw NotEnoughNumbersStored();
	else
	{
		std::vector<int> temp;
		std::vector<int>::iterator min;

		temp = _values;
		std::sort(temp.begin(), temp.end());
		std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
		min = std::min_element(temp.begin() + 1, temp.end());
		return (*min);
	}
}

unsigned int Span::longestSpan()
{
	if (_values.size() <= 1)
		throw NotEnoughNumbersStored();
	else
	{
		std::vector<int>::iterator max;								// iterator is like a pointer that points to an elements position in the container
		std::vector<int>::iterator min;

		max = std::max_element(_values.begin(), _values.end());
		min = std::min_element(_values.begin(), _values.end());

		return (*max - *min);										// to use the actual values we need to dereference the iterators
	}
}
