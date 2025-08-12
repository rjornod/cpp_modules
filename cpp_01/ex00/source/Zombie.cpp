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
// int main(void)
// {
// 	std::cout	<< "HEAP ZOMBIES"
// 				<< std::endl
// 				<< std::endl;

// 	Zombie* zombie1 = newZombie("Russell");
// 	zombie1->announce();
// 	Zombie* zombie2 = newZombie("Lu");
// 	zombie2->announce();

// 	std::cout	<< std::endl
// 				<< "STACK ZOMBIES"
// 				<< std::endl;
// 	randomChump("Nick");
// 	randomChump("Jaylin");
// 	std::cout << std::endl;
// 	delete zombie1;
// 	delete zombie2;

// }