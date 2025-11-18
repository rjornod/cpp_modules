#include "../include/ClapTrap.hpp"

int main ()
{
	ClapTrap first("test");
	std::cout << first.getName() << std::endl;
	first.takeDamage(9);
	first.beRepaired(8);
	first.attack("porto");
}