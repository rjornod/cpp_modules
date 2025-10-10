#include <iostream>
#include "../include/Harl.hpp"

void Harl::debug( void )
{
	std::cout 	<< GREEN
				<< "[ DEBUG ]" << std::endl << std::endl
				<< WHITE
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
				<< std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout 	<< BLUE
				<< "[ INFO ]" << std::endl << std::endl
				<< WHITE
				<< "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!"
				<< std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout 	<< YELLOW
				<< "[ WARNING ]" << std::endl << std::endl
				<< WHITE
				<< "I think I deserve to have some extra bacon for free. Ive been coming for years, whereas you started working here just last month."
				<< std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout 	<< RED
				<< "[ ERROR ]" << std::endl << std::endl
				<< WHITE
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
}

/**
 * 
 * 	Here we create an array of 4 pointers to member functions - void (Harl::*member_functions[4])(void)
 * 	We use references to the functions because we do not want to execute them directly, we are storing them for later use
 * 	The member functions get called in case the parameter <level> is equal to one of the <levels> in our string array
 * 	this->member_functions[i]() - <this> points to the current object being called in complain (Harl object)
 * 	Member functions need an object to work, hence why we use <this>
 * 
 */

void Harl::complain( std::string level )
{
	void (Harl::*member_functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //functions is an array of 4 pointers to member functions of the harl class
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*member_functions[i])();
			return;			
		}
	}
	std::cout << "Level not recognized" << std::endl;
}
