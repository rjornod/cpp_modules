#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
	public:
		void	attack(std::string name, Weapon);
		HumanA();
		~HumanA();
}