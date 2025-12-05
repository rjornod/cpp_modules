#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "../include/WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat &operator=(const WrongCat& other);
		WrongCat(const WrongCat& copy);
		~WrongCat();
};

#endif