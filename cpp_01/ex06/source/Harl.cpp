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

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0:
					Harl::debug();
				case 1:
					Harl::info();
				case 2:
					Harl::warning();
				case 3:
					Harl::error();
				return;
					
			}
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
