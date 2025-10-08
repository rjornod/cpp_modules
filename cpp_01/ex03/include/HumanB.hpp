#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "../include/Weapon.hpp"
/**
 * 
 * 	HumanB will not always have a weapon equipped so that value can be null
 * 	Because of this we should use a pointer to Weapon because a pointer can be null
 * and a reference must always have a value 
 * 
 */
class HumanB {
	private:
		std::string _name;
		Weapon *_weapon; //pointer. can be null to represent no weapon
	public:
		HumanB(const std::string &name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif