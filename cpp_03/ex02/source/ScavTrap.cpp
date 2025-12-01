#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default Scav")
{
	std::cout << "Default ScavTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Parameterized ScavTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
		std::cout << "ScavTrap has no hitpoints so it can't guard the gate!" << std::endl;
	else
		std::cout << "ScavTrap is now in gatekeeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if ( _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy so it can't attack!" << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no hitpoints so it can't attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " strikes " << target <<  " dealing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints = _energyPoints - 1;
}
