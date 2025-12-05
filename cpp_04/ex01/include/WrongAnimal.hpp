#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal &operator=(const WrongAnimal& other);
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal();
		
		virtual void 		makeSound() const;
		const std::string 	getType() const;
};

#endif