/*Name, which is passed as a parameter to the constructor
• Hit points (10), representing the health of the ClapTrap
• Energy points (10)
• Attack damage 
*/
#include <iostream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class ClapTrap{
	private: 
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

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		void showStats();		
};