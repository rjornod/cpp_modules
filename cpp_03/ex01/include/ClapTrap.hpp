#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
/**
 * 
 *  	attack is declared as virtual so we can change the message for the ScavTrap attack. 
 *  	virtual functions allow derived classes to override them with their own implementation.
 * 		if a class contains any virtual functions, the destructor must also be virtual
 * 
 * 		the private members are now protected because private members would not be accessible in
 * derived classes. protected members can be accessed in derived classes but not form outside.
 */
class ClapTrap{
	protected: 
		std::string		_name;
		int	_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int 	_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator=(const ClapTrap& overload);

		virtual void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		void showStats();
};

#endif