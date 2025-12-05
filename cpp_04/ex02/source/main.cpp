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

int main()
{
	const int 	size = 2;
	int 		i = 0;
	
	std::cout << RED << "CONSTRUCTORS" << WHITE << std::endl;
	Animal* animals[size];
	for (i = 0; i < size / 2; i++)
	{
		animals[i] = new Dog();
	}
	for (i = size / 2; i < size; i++)
	{
		animals[i] = new Cat();
	}
	const Animal* dog1 = new Dog();
	const Animal* cat1 = new Cat();
	
	std::cout << RED << "DESTRUCTORS" << WHITE << std::endl;
	for (i = 0; i < size; i++)
	{
		delete animals[i];
	}
	
	delete cat1; //should not create a leak
	delete dog1;

	return 0;
}