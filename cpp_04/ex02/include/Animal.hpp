#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>


/**
 * 
 * virtual void abstractFunc() = 0; - this is a pure virtual function
 * any class with a pure virtual function is abstract and the compiler forbids
 * creating any objects of that class (non instantiable)
 * 
 * Animal newAnimal; doesn't work
 * Animal* p = new Dog(); this works
 * Dog d; Animal& r = d;  this works
 * pointers and references to the class are still allowed
 * because they dont create an object of the abstract class, 
 * they only refer to an already existing derived object
 * 
 */
class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal &operator=(const Animal& other);
		Animal(const Animal& copy);
		virtual ~Animal();

		virtual void 		makeSound() const = 0;
		const std::string 	getType() const;
		virtual void 		setIdea(std::string idea);
		virtual void		printIdeas(unsigned int amount);
};

#endif