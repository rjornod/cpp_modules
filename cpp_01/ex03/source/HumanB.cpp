#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
	public:
		void	attack(std::string name, Weapon);
		HumanB();
		~HumanB();
}