#include <iostream>
#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "Bird";
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "Parameterized WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Assigment Operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "ChirpChirp" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return _type;

}