#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other); // calls on the parents assigment operator to copy base class data
		delete _brain; // deletes old brain object, prevents leaks
		_brain = new Brain(*other._brain); // this is the deep copy, it allocates a new brain object thats being copied from other
	}
	return *this;
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meoooow" << std::endl;
}

void Cat::setIdea(std::string idea)
{
	this->_brain->setIdea(idea);
}

void Cat::printIdeas(unsigned int amount)
{
	this->_brain->printIdea(amount);
}
