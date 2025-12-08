#include "../include/Brain.hpp"

Brain::Brain() : _ideasNr(0)
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy Assignment operator" << std::endl;
	if (this != &other)
	{
		this->_ideasNr = other._ideasNr;
		for (int i = 0; i <= 99; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::Brain(const Brain& copy)
{
	this->_ideasNr = copy._ideasNr;
	for (int i = 0; i <= 99; i++)
	{
		_ideas[i] = copy._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

void Brain::setIdea(const std::string& idea)
{
	if (_ideasNr > 99)
	{
		std::cout << "Brain is already full of ideas!" << std::endl;
		return ;
	}
	_ideas[_ideasNr] = idea;
	_ideasNr++;
}

void Brain::printIdea(unsigned int amount)
{
	if (amount > 100)
		amount = 100;
	for (unsigned int j = 0; j < amount; j++)
		std::cout << j + 1 << " - " <<  _ideas[j] << std::endl;
}