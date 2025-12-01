#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

// #include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("Diamond");

	std::cout << "\n Who am I?" << std::endl;
	diamond.whoAmI();

	diamond.showStats();
	std::cout << std::endl <<  "Inherited functions" << std::endl;
	diamond.attack("bandit"); // ScavTrap's attack with FragTrap's damage
	diamond.takeDamage(25);  // inherited from ClapTrap
	diamond.beRepaired(10);  // inherited from ClapTrap

	
	std::cout << std::endl << "Inherited abilities " << std::endl;
	diamond.guardGate(); // inherited from ScavTrap
	diamond.highFivesGuys(); // inherited from FragTrap

	std::cout << std::endl << "Copy constructor" << std::endl;
	DiamondTrap copy(diamond);
	copy.whoAmI();

	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	DiamondTrap assignment("Assigned");
	assignment = diamond;
	assignment.whoAmI();

	std::cout << "\n--- Edge Case: Multiple Inheritance Test ---" << std::endl;
	DiamondTrap multi("Multi");

	// Test that we only have one ClapTrap instance
	multi.attack("TestTarget");
	multi.guardGate();
	multi.highFivesGuys();
	multi.whoAmI();

	std::cout << "\n--- Destruction Chaining Test ---" << std::endl;
	return 0;
}