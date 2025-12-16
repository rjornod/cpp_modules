#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

/**
 * 
 *  destructor is virtual to make sure the correct one gets called for derived class objects
 *  if it wasn't virtual only the Animal destructor would get called and not Cat's, leading to memory leaks
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

		virtual void 		makeSound() const;
		const std::string 	getType() const;
};

#endif