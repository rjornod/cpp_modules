#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
	private:
		std::string _type;
	public:
		//member function that returns a const reference to the type
		const	std::string& getType() const;

		//member function that sets the type using the value passed as a parameter 
		void	setType( std::string type );

		Weapon(std::string weapon);
		~Weapon();
};

#endif