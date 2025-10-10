#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main()
{
	std::cout << BLUE << "════════ HUMAN BOB ════════" << WHITE << std::endl;
	Weapon weapon1 = Weapon("crude spiked club");
	HumanA bob("Bob", weapon1);
	bob.attack();
	weapon1.setType("some other type of club");
	bob.attack();


	std::cout << std::endl << YELLOW << "════════ HUMAN JIM ════════" << WHITE << std::endl;
	Weapon weapon2 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(weapon2);
	jim.attack();
	weapon2.setType("some other type of club");
	jim.attack();
	return 0;
}