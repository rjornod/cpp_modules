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
	const int 	size = 4;
	int 		i = 0;
	
	// Proof that Animal is not instantiable anymore
	// Animal dog; <- this doesn't work anymore because a not instantiable class can't create objects
	
	
	std::cout << RED << "CONSTRUCTORS" << WHITE << std::endl;
	std::cout << RED << "animals array constructors" << WHITE << std::endl;
	
	// Creating an array of Animals, half of them will be assigned Cat class 
	// the other hallf will be assigned a Dog class
	Animal* animals[size];
	for (i = 0; i < size / 2; i++)
	{
		animals[i] = new Dog();
	}
	for (i = size / 2; i < size; i++)
	{
		animals[i] = new Cat();
	}

	std::cout << std::endl << RED << "original_cat and copy_cat constructors" << WHITE << std::endl;
	Cat original_cat;

 	// Setting some ideas for the original cat
	original_cat.setIdea("First Idea");
	original_cat.setIdea("Second Idea");
	original_cat.setIdea("Third Idea");

	// Creating a new cat and copying the contents of original cat into it
	// Cat copy_cat = original_cat;
	Cat copy_cat;

	copy_cat = original_cat;
	
	std::cout << std::endl << RED << "ARRAY CHECK - HALF DOG, HALF CAT" << WHITE << std::endl;
	for (int j = 0; j < size; j++)
	{
		std::cout << "Animal " << j	<< " is a " << BLUE << animals[j]->getType() << WHITE << std::endl;
	}

	// Priting the ideas of both cats, output should be the same
	std::cout << std::endl<< RED << "--- ORIGINAL_CAT IDEAS ---" << WHITE << std::endl;
	original_cat.printIdeas(4);
	std::cout << RED << "--- COPY_CAT IDEAS ---" << WHITE << std::endl;
	copy_cat.printIdeas(4);

	std::cout << GREEN << std::endl << "adding new ideas .........." << std::endl;
	// Setting a new idea for original_cat
	original_cat.setIdea("I am original cat idea");
	std::cout << std::endl;

	// Setting new ideas for copy_cat
	copy_cat.setIdea("I am copy cat idea");
	copy_cat.setIdea("I am another copy cat idea");

	// Printing the ideas for both cats, first 3 idas are the same and the 4th is different for each
	std::cout << RED << "--- ORIGINAL_CAT IDEAS AFTER ADDING ---" << WHITE << std::endl;
	original_cat.printIdeas(5);
	std::cout << RED << "--- COPY_CAT IDEAS AFTER ADDING ---" << WHITE << std::endl;
	copy_cat.printIdeas(5);

	std::cout << std::endl << RED << "DESTRUCTORS" << WHITE << std::endl;
	for (i = 0; i < size; i++)
	{
		delete animals[i];
	}

	return 0;
}