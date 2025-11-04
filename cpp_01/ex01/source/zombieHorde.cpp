#include "../include/Zombie.hpp"
#include <iostream>

/**
 * 
 * 	Zombie *zombie: holds the address to the first zombie in the array created by <new>
 */
Zombie* zombieHorde( int N, std::string name )
{
		Zombie *zombie = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			zombie[i].setName(name);
			zombie[i].announce();
		}
		std::cout << std::endl;
		return zombie;
}
