#ifndef DOG_HPP
#define DOG_HPP
#include "../include/Animal.hpp"
#include "../include/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(std::string type);
		Dog &operator=(const Dog& other);
		Dog(const Dog& copy);
		virtual ~Dog();

		void makeSound() const override;
		std::string getIdea();
		void 		setIdea(std::string idea);
};

#endif