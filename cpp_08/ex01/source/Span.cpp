#include <Span.hpp>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

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
	if (amount < _max && (_values.size() + amount) < _max) // check if amount to fill the span with would fit in _max
	{
		std::generate_n(std::back_inserter(_values), amount, [](){ return rand();});
		std::cout << "amount fits" << std::endl;
	}
	else  // if not I calculate how much the vector can still hold and then i fill it
	{
		std::cout << "amount doesnt fit" << std::endl;
		amount = _max - _values.size();
		std::generate_n(std::back_inserter(_values), amount, [](){ return rand();});
	}
	std::cout << "Amount of values: " << _values.size() << std::endl;
}

void Span::addNumber(unsigned int N)
{
	if (std::size(_values) < _max)
		_values.push_back(N);
	else
		throw std::out_of_range("Span is already full");
	for (int value : _values) 
	{
    	std::cout << value << " ";
	}
	std::cout << std::endl;
}

unsigned int Span::shortestSpan() // TO DO : shortest span needs to be fixed
{
	if (std::size(_values) <= 1)
		throw NotEnoughNumbersStored();
	else
	{
		std::vector<int> temp;
		temp = _values;
		std::sort(temp.begin(), temp.end());
		return (temp.at(1) - temp.at(0));
	}
}

unsigned int Span::longestSpan()
{
	if (std::size(_values) <= 1)
		throw NotEnoughNumbersStored();
	else
	{
		std::vector<int> temp;
		temp = _values;
		std::sort(temp.begin(), temp.end());
		return (temp.at(std::size(temp) - 1) - temp.at(0));
	}
}