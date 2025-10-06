#include "../include/Weapon.hpp"

const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon()
{
	std::cout << _type << " weapon created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << _type << " weapon destroyed" << std::endl;
}