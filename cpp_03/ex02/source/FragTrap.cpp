#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default Scav")
{
	std::cout << "Default FragTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parameterized FragTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called for " << _name << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoints <= 0)
		std::cout << "FragTrap has no hitpoints so it can't request a high five!" << std::endl;
	else
		std::cout << "FragTrap is asking you for a high five!" << std::endl;
}


