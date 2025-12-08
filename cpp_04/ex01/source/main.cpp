#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"
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
	for (i = 1; i < size; i++)
	{
		animals[i] = new Cat();
	}
	Animal* dog1 = new Dog();
	Animal* cat1 = new Cat();
	Cat original_cat;

 	// Setting some ideas for the original cat
	original_cat.setIdea("First Idea");
	original_cat.setIdea("Second Idea");
	original_cat.setIdea("Third Idea");

	// Creating a new cat and setting copying the contents of original cat into it
	Cat copy_cat = original_cat;
	
	// Pritins the ideas of both cats, output should be the same
	std::cout << std::endl<< RED << "--- ORIGINAL_CAT IDEAS ---" << WHITE << std::endl;
	original_cat.printIdeas(4);
	std::cout << RED << "--- COPY_CAT IDEAS ---" << WHITE << std::endl;
	copy_cat.printIdeas(4);

	// Setting a new idea for original_cat
	original_cat.setIdea("I am original cat idea");
	std::cout << std::endl;

	// Setting a new idea for copy_cat
	copy_cat.setIdea("I am copy cat idea");

	// Printing the ideas for both cats, first 3 idas are the same and the 4th is different for each
	std::cout << RED << "--- ORIGINAL_CAT IDEAS AFTER ADDING ---" << WHITE << std::endl;
	original_cat.printIdeas(4);
	std::cout << RED << "--- COPY_CAT IDEAS AFTER ADDING ---" << WHITE << std::endl;
	copy_cat.printIdeas(4);

	std::cout << RED << "DESTRUCTORS" << WHITE << std::endl;
	for (i = 0; i < size; i++)
	{
		delete animals[i];
	}
	
	delete cat1; //should not create a leak
	delete dog1;

	return 0;
}