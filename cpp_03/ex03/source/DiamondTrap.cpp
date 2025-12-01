#include "../include/ClapTrap.hpp"
#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	_name = "Default DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}
DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap Desctructor called for " << _name << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "Parameterized DiamondTrap constructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI() 
{
	std::cout << GREEN << "Name: " << WHITE << _name << std::endl;
	std::cout << GREEN << "ClapTrap name: " << WHITE << ClapTrap::_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}
DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}
void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::showStats()
{
	std::cout << std::endl << RED <<"Stats for " << _name << WHITE << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy points: " << _energyPoints << std::endl;
	std::cout << "Attack damage: " << _attackDamage << std::endl;
	
}