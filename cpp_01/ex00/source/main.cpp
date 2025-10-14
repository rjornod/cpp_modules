#include "../include/Zombie.hpp"

int main(void)
{
	std::cout	<< BLUE
				<< "╔════════ CREATING HEAP ZOMBIES ════════╗"
				<< WHITE
				<< std::endl
				<< std::endl;

	Zombie* zombie1 = newZombie("Russell");
	Zombie* zombie2 = newZombie("Lu");
	
	std::cout	<<	std::endl
				<< BLUE
				<< "╚══════════════════════════════════════╝"
				<< WHITE; 

	std::cout	<< std::endl
				<< YELLOW
				<< "╔════════ CREATING STACK ZOMBIES ════════╗"
				<< WHITE
				<< std::endl
				<< std::endl;
	randomChump("Nick");
	randomChump("Jaylin");
	std::cout	<< std::endl
				<< YELLOW
				<< "╚════════════════════════════════════════╝"
				<< WHITE;
	std::cout << std::endl;
	std::cout	<< BLUE
				<< "╔════════ DELETING HEAP ZOMBIES ════════╗"
				<< WHITE
				<< std::endl
				<< std::endl;
	delete zombie1;
	delete zombie2;
	std::cout	<<	std::endl
				<< BLUE
				<< "╚═══════════════════════════════════════╝"
				<< WHITE
				<< std::endl
				<< std::endl;
}