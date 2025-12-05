#include "../include/Brain.hpp"

Brain::Brain()
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
	
	}
	return *this;
}

Brain::Brain(const Brain& copy)
{
	(void)copy;
	std::cout << "Brain copy constructor called" << std::endl;
}