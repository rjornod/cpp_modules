#ifndef CAT_HPP
#define CAT_HPP
#include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat &operator=(const Cat& other);
		Cat(const Cat& copy);
		virtual ~Cat();

		void makeSound() const override;
};

#endif