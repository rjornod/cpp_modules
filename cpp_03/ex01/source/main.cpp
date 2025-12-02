#include "../include/ScavTrap.hpp"

int main ()
{
	std::cout << std::endl << RED << "CONSTRUCTORS" << WHITE << std::endl;
	ClapTrap first("CLAP");
	ScavTrap scav("SCAV");
	
	std::cout << std::endl << RED << "CLAPTRAP" << WHITE;
	first.showStats();
	first.attack("their rival");

	std::cout << std::endl << RED << "SCAVTRAP" << WHITE;

	scav.showStats();
	scav.takeDamage(34); 			// has been inherited from ClapTrap but message hasn't changed
	scav.beRepaired(20);			// has been inherited from ClapTrap but message hasn't changed
	scav.attack("their opponent");	// has been inherited from ClapTrap and the message has been changed
	scav.guardGate();

	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
}