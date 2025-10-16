#include "../include/Zombie.hpp"
#include <ostream>

std::string Zombie::getName()
{
	return _name;
}

void	Zombie::announce(void)
{
	std::cout	<< getName() 
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout	<< getName()
				<< " created"
				<< std::endl;
}

Zombie::~Zombie()
{
	std::cout	<< getName() 
				<< " destroyed"
				<<std::endl;
}
