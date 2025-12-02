#include "../include/Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal()
{
	_type = type;
	std::cout << "Cat Parameterized Constructor called" << std::endl;

}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
