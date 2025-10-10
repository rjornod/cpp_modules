#include "../include/Zombie.hpp"

int main(void)
{
	std::cout	<< BLUE
				<< "╔════════ HEAP ZOMBIES ════════╗"
				<< WHITE
				<< std::endl
				<< std::endl;

	Zombie* zombie1 = newZombie("Russell");
	Zombie* zombie2 = newZombie("Lu");
	delete zombie1;
	delete zombie2;
	std::cout	<<	std::endl
				<< BLUE
				<< "╚═══════════════════════════════╝"
				<< WHITE; 

	std::cout	<< std::endl
				<< YELLOW
				<< "╔════════ STACK ZOMBIES ════════╗"
				<< WHITE
				<< std::endl
				<< std::endl;
	randomChump("Nick");
	randomChump("Jaylin");
	std::cout	<<	std::endl
				<< YELLOW
				<< "╚═══════════════════════════════╝"
				<< WHITE;
	std::cout << std::endl;
}