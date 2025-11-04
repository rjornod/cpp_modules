#include "../include/Zombie.hpp"


/**************************************************************************
 *
 * 	-this function gets allocated in the stack, meaning everything is done
 * automatically (allocaton, destructor call and deallocation)
 * 
**************************************************************************/
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}  