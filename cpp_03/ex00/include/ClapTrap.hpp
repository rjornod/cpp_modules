/*Name, which is passed as a parameter to the constructor
• Hit points (10), representing the health of the ClapTrap
• Energy points (10)
• Attack damage 
*/
#include <iostream>
class ClapTrap{
	private: 
		std::string		_name;
		int	_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int 	_attackDamage;

	public:
		ClapTrap( std::string name);
		~ClapTrap();
		ClapTrap( const ClapTrap& copy );
		ClapTrap &operator=(const ClapTrap& overload);

		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		std::string  getName();
};