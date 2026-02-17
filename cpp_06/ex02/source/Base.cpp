#include "../include/Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"

// Destructor
Base::~Base() {
    // std::cout << "Base destructor called" << std::endl;
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
		std::cout << "Pointer type is" << RED <<" A" << WHITE << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "Pointer type is" << RED <<" B" << WHITE << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "Pointer type is" << RED <<" C" << WHITE << std::endl;
	else 
		std::cout << "Type doesn't exist" << std::endl;
}

void Base::identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference type is" << RED <<" A" << WHITE << std::endl;
	}
	catch (std::bad_cast)
	{
		// std::cout << "Not type A" << std::endl;
	}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference type is" << RED <<" B" << WHITE << std::endl;
	}
	catch (std::bad_cast)
	{
		// std::cout << "Not type B" << std::endl;
	}
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference type is" << RED <<" C" << WHITE << std::endl;
	}
	catch (std::bad_cast)
	{
		// std::cout << "Not type C" << std::endl;
	}
}


