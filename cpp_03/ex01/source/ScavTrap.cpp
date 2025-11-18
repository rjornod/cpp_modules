#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gatekeeper mode!" << std::endl;
}