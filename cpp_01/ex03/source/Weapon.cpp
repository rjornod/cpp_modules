#include "../include/Weapon.hpp"
/**
 * 
 *	returns a read-only string (first const)
 *	because this is a const method, it doesn't allow the user to change variable values
 * 
 **/
const std::string &Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

Weapon::~Weapon()
{
}