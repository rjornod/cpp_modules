#include "../include/Zombie.hpp"

int main()
{
	std::cout << "CREATING HORDE OF RUSSELS" << std::endl;
	Zombie* zombiehorde1 = zombieHorde(3, "Russell");
	std::cout << "CREATING HORDE OF KEVINS" << std::endl;
	Zombie* zombiehorde2 = zombieHorde(4, "Kevin");
	delete [] zombiehorde1;
	delete [] zombiehorde2;
}