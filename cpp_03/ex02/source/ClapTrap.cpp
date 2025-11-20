#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Defualt ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Paremeterized ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& copy ) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignement operator called" << std::endl;	
	return *this;
}

std::string ClapTrap::getName()
{
	return ( _name );
}

void ClapTrap::beRepaired( unsigned int amount )
{
	if ( _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy so it can't repair hitself!" << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hitpoints so it can't repair hitself!" << std::endl;
		return;
	}
	_hitPoints = _hitPoints + amount;

	std::cout << "ClapTrap " << _name << " repaired for " << amount <<" hit points! It now has " << _hitPoints << " hit points!" << std::endl;
	_energyPoints = _energyPoints - 1;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if ( _hitPoints >= 0 && amount > (unsigned int)_hitPoints )
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;

	std::cout << "ClapTrap " << _name << " took  " << amount <<" points of damage! It now has " << _hitPoints << " hit points!" << std::endl;
}

void ClapTrap::attack( const std::string& target)
{
	if ( _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy so it can't attack!" << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hitpoints so it can't attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target <<  " causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints = _energyPoints - 1;
}