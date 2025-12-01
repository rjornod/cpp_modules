#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

// #include "DiamondTrap.hpp"

int main(void)
{
	std::cout << std::endl << RED << "CONSTRUCTORS" << WHITE << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << std::endl << RED << "WHO AM I?" << WHITE << std::endl;
	diamond.whoAmI();

	diamond.showStats();
	std::cout << std::endl << RED <<  "INHERITED FUNCTIONS" << WHITE << std::endl;
	diamond.attack("bandit"); // ScavTrap's attack with FragTrap's damage
	diamond.takeDamage(25);  // inherited from ClapTrap
	diamond.beRepaired(10);  // inherited from ClapTrap

	
	std::cout << std::endl << RED << "INHERITED ABILITIES " << WHITE << std::endl;
	diamond.guardGate(); // inherited from ScavTrap
	diamond.highFivesGuys(); // inherited from FragTrap

	std::cout << RED << std::endl << "COPY CONSTRUCTOR" << WHITE << std::endl;
	DiamondTrap copy(diamond);
	copy.whoAmI();

	std::cout << RED << std::endl  << "ASSIGNMENT OPERATOR" << WHITE << std::endl;
	DiamondTrap assignment("Assignation");
	assignment = diamond;
	assignment.whoAmI();
	assignment.showStats();

	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
	return 0;
}