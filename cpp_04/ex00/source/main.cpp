#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

/**
 * 
 * 	Polymorphism: when an object can have many forms, using different implementations of an abstract/virtual class. 
 * Each class inherits some features from the parent class, but implement its functions differently, hence "many forms"
 * 
 */

int main()
{
	std::cout << std::endl << RED << "CONSTRUCTORS" << WHITE << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); // pointer to an Animal object but the actual object being created is a Dog
	const Animal* i = new Cat();
	const WrongAnimal* f = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl << RED << "TYPES" << WHITE << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;


	std::cout << std::endl << RED << "SOUNDS" << WHITE << std::endl;
	std::cout << GREEN << "Default Animal " << WHITE << "sound: " << WHITE;
	meta->makeSound(); //outputs the default animal sound: ZzZzZzZzZZzZzZzZzZ
	std::cout << GREEN << "Cat " << WHITE << "sound: ";
	i->makeSound(); //outputs Meow!
	std::cout << GREEN << "Dog " << WHITE << "sound: ";
	j->makeSound(); //outputs Woof!
	std::cout << BLUE << "WrongCat " << WHITE << "sound: " << WHITE;
	k->makeSound(); //outputs ChirpChirp
	std::cout << BLUE << "WrongAnimal " << WHITE << "sound: " << WHITE;
	f->makeSound(); //outputs ChirpChirp

	
	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
	delete meta;
	delete j;
	delete i;
	delete f;
	delete k;
}