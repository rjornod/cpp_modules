#include <iostream>
#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name)
{

}

HumanB::~HumanB(void)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout	<< _name
				<< " attacks with "
				<< _weapon->getType()
				<< std::endl;
}