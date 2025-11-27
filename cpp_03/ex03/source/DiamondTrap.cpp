#include "../include/ClapTrap.hpp"
#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default Diamond")
{
	_name = "Default DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap() {}
// DiamondTrap::DiamondTrap(const DiamondTrap& copy) {}
// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "Parameterized DiamondTrap constructor called" << std::endl;
}
void DiamondTrap::whoAmI() 
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}