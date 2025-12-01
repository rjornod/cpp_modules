#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap{
	protected: 
		std::string		_name;
		int	_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int 	_attackDamage;

	public:
		ClapTrap();
		ClapTrap( std::string name);
		~ClapTrap();
		ClapTrap( const ClapTrap& copy );
		ClapTrap &operator=(const ClapTrap& overload);

		virtual void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		
};

#endif