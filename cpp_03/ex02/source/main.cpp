#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main ()
{
	ClapTrap first("test");
	ScavTrap scav("scav");
	FragTrap frag("frag");

	first.takeDamage(9);
	first.beRepaired(8);
	first.attack("their rival");


	scav.attack("a scoundrel");
	scav.attack("their opponent");
	scav.guardGate();

	frag.highFivesGuys();
}