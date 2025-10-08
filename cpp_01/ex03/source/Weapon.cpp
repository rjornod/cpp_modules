#include "../include/Weapon.hpp"

const std::string& Weapon::getType() const
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