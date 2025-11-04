#include <iostream>
#include "../include/Zombie.hpp"

std::string Zombie::getName()
{
	return _name;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout	<< getName() 
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}

Zombie::Zombie() : _name("")
{
	std::cout	<< "Zombie created"
				<<std::endl;
}

Zombie::~Zombie()
{
	std::cout	<< getName() 
				<< " destroyed"
				<<std::endl;
}