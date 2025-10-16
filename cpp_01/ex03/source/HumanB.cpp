#include <iostream>
#include "../include/HumanB.hpp"

/**
 * 
 * 	HumanB does not take the weapon in its contructor so we only initialize <name>
 * in the member initialization list
 * 
 */

HumanB::HumanB(const std::string &name) : _name(name), _weapon(nullptr)
{

}

HumanB::~HumanB(void)
{

}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

/**********************************************************************
 * 
 * 	-> arrow operator: calls getType method on the object it points to
 * same as (*_weapon).getType(). works with pointers to an object
 * 
 *********************************************************************/
void HumanB::attack(void)
{
	if (_weapon){
		std::cout	<< _name
				<< " attacks with their "
				<< _weapon->getType()
				<< std::endl;
	}
	else 
		std::cout	<< "no weapon" << std::endl;
}