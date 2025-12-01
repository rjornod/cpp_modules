#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main ()
{

	FragTrap frag("frag");
	FragTrap frag2;
	ScavTrap scav1;

	frag.highFivesGuys();
	frag.showStats();
	scav1.showStats();
}