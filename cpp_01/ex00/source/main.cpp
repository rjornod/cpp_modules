#include "../include/Zombie.hpp"

int main(void)
{
	std::cout	<< "╔════════ HEAP ZOMBIES ════════╗"
				<< std::endl
				<< std::endl;

	Zombie* zombie1 = newZombie("Russell");
	zombie1->announce();
	Zombie* zombie2 = newZombie("Lu");
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	std::cout	<<	std::endl
				<< "╚═══════════════════════════════╝";

	std::cout	<< std::endl
				<< "╔════════ STACK ZOMBIES ════════╗"
				<< std::endl
				<< std::endl;
	randomChump("Nick");
	randomChump("Jaylin");
	std::cout	<<	std::endl
				<< "╚═══════════════════════════════╝";
	std::cout << std::endl;
}