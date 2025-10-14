#include <iostream>
#include "../include/HumanA.hpp"


/*****************************************************************************************
 * 
 * 	: _name(name), _weapon(weapon): this part of the code is a member initialization list
 * it initializes both _name and _weapon to name and weapon
 * references must be initialized when declared and cannot be reassigned later
 * you cannot initialize a reference within the constructor body
 * 	since HumanA will always have a weapon it is better to pass it as a reference, meaning
 * it will always have a value, cannot be null
 * 
 ****************************************************************************************/
HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{

}

HumanA::~HumanA(void)
{

}
/**
 * 
 * 	. dot operator works with only with objects. if working with pointers
 * to an object it is required to use the -> arrow operator
 * 
 */
void HumanA::attack(void)
{
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}
