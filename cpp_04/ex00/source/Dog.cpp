#include "../include/Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal()
{
	_type = type;
	std::cout << "Dog Parameterized Constructor called" << std::endl;

}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}