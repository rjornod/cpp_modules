#include "../include/ClapTrap.hpp"

int main ()
{
	std::cout << std::endl << RED << "CONSTRUCTORS" << WHITE << std::endl;
	ClapTrap first("test");
	ClapTrap second;

	first.showStats();
	first.takeDamage(9);
	first.beRepaired(8);
	first.attack("a bandit");
	
	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
}