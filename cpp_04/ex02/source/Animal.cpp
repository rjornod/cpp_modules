#include "../include/Animal.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

Animal::Animal()
{
	_type = "Default Animal";
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Parameterized Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal Copy Assigment Operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "ZzZzZzZzZZzZzZzZzZ" << std::endl;
}

const std::string Animal::getType() const
{
	return _type;
}

void Animal::setIdea(std::string idea)
{
	(void)idea;
	std::cout << "animal setidea called" << std::endl;
}

void Animal::printIdeas(unsigned int amount)
{
	(void)amount;
	std::cout << "animal getidea called" << std::endl;
}
