#ifndef FRAGPTRAP_HPP
#define FRAGPTRAP_HPP

#include "../include/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		using ClapTrap::ClapTrap;
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap( const FragTrap& copy);
		FragTrap &operator=(const FragTrap& overload);
		void highFivesGuys(void);
};

#endif