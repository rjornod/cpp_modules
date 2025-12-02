#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class ClapTrap{
	protected: 
		std::string		_name;
		int				_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int 	_attackDamage;

	public:
		ClapTrap();
		ClapTrap( std::string name);
		virtual ~ClapTrap();
		ClapTrap( const ClapTrap& copy );
		ClapTrap &operator=(const ClapTrap& overload);

		virtual void attack( const std::string& target );
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif