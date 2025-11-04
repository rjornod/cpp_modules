#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../include/Weapon.hpp"
/**
 * 
 * 	HumanA will always have a weapon equipped
 * 	Since that value can never be null, using a reference to the weapon is the best
 * way to handle it. A reference is always valid
 * 
 */
class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif