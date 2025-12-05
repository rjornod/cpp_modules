#ifndef CAT_HPP
#define CAT_HPP
#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(std::string type);
		Cat &operator=(const Cat& other);
		Cat(const Cat& copy);
		virtual ~Cat();

		void makeSound() const override;
		std::string getIdea();
		void 		setIdea(std::string idea);

};

#endif