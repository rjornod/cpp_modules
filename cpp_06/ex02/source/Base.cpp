#include "../include/Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

// Destructor
Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate(void)
{
	int random = rand() % 3 + 1; // generates a random number between 1 and 3
	switch (random)
	{
	case 1:
		return new A;
		break;
	case 2:
		return new B;
		break;
	case 3:
		return new C;
		break;
	}
	return nullptr;
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Type is C" << std::endl;
	else 
		std::cout << "Type doesn't exist" << std::endl;
}

// void Base::identify(Base& p)
// {

// }


