#include <iostream>
#include "../include/HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{

}

HumanA::~HumanA(void)
{

}

void HumanA::attack(void)
{
	std::cout	<< _name
				<< " attacks with "
				<< _weapon.getType()
				<< std::endl;
}
