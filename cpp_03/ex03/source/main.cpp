#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main ()
{
	DiamondTrap dia("diamond");
	dia.whoAmI();
	dia.attack("enemy");
}