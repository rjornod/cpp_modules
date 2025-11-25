#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap& overload);
		DiamondTrap (const DiamondTrap& copy);
		void whoAmI();
};
