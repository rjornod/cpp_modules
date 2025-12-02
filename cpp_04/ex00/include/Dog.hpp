#ifndef DOG_HPP
#define DOG_HPP
#include "../include/Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog &operator=(const Dog& other);
		Dog(const Dog& copy);
		virtual ~Dog();

		void makeSound() const override;
};

#endif