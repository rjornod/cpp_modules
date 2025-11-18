#include "../include/ScavTrap.hpp"

int main ()
{
	ClapTrap first("test");
	ScavTrap scav("scav");

	std::cout << scav.getName() << std::endl;
	first.takeDamage(9);
	first.beRepaired(8);
	first.attack("porto");
}