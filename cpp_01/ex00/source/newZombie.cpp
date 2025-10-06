#include "../include/Zombie.hpp"

/*****************************************************************
 *
 * 	-this function gets allocated in the heap so it can be used
 * even after the function returns.
 *	-allocation is done via the <new> keyword
 *	-to free something in cpp you need to use the keyword <delete>
 *
******************************************************************/
Zombie* newZombie( std::string name )
{
	Zombie* zombie = new Zombie(name);
	zombie->announce();
	return zombie;
}