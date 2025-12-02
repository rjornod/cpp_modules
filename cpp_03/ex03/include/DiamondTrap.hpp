#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap& overload);
		DiamondTrap(const DiamondTrap& copy);
		
		void attack(const std::string& target);
		void whoAmI();
		void showStats();
};

#endif