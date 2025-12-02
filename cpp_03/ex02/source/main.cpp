#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main ()
{
	std::cout << std::endl << RED << "CONSTRUCTORS" << WHITE << std::endl;
	FragTrap frag("FRAG");
	ClapTrap first("CLAP");
	
	std::cout << std::endl << RED << "FRAGTRAP" << WHITE;

	frag.showStats();
	frag.takeDamage(34); 			// has been inherited from ClapTrap but message hasn't changed
	frag.beRepaired(20);			// has been inherited from ClapTrap but message hasn't changed
	frag.attack("their opponent");	// has been inherited from ClapTrap but message hasn't changed
	frag.highFivesGuys();

	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
}