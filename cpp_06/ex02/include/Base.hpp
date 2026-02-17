#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>


class Base
{
	public:    
		// Destructor
		virtual ~Base();

		// It randomly instantiates A, B, or C and returns the instance as a Base pointer
		Base * generate(void);

		// It prints the actual type of the object pointed to by p: "A", "B", or "C"
		void identify(Base* p);

		// It prints the actual type of the object referenced by p: "A", "B", or "C"
		void identify(Base& p);
};

#endif
