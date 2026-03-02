#include <Span.hpp>
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _max(N)
{

}

Span::~Span()
{}

Span::Span(const Span& other) : _max(other._max), _values(other._values)
{

}

// Span& Span::operator=(const Span& other)
// {

// }

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

unsigned int Span::shortestSpan()
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