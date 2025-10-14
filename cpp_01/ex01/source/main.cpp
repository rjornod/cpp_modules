#include "../include/Zombie.hpp"

/*********************************************************************************
 * 
 * 	-the way to deallocate something allocated by <new> is to use <delete>
 * 	-if an array was allocated then the way to deallocate is  <delete [] varname>
 * 	-delete calls the destructor for the objects and deallocates the allocated
 * memory
 * 
 *********************************************************************************/
int main()
{
	std::cout 	<< YELLOW 
				<< "════════ CREATING HORDE OF RUSSELS ════════" 
				<< WHITE 
				<<std::endl;

	Zombie *zombiehorde1 = zombieHorde(3, "Russell");

	std::cout 	<< BLUE 
				<< "════════ CREATING HORDE OF KEVINS ════════" 
				<< WHITE 
				<<std::endl;

	Zombie *zombiehorde2 = zombieHorde(4, "Kevin");

	std::cout	<< RED 
				<< "════════ DEALLOCATING AND CALLING DESTRUCTORS ════════" 
				<< WHITE 
				<<std::endl;

	delete [] zombiehorde1;
	delete [] zombiehorde2;
}