#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# define RED "\033[1;31m"
# define WHITE "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

class Intern
{
	public:
		// Default Constructor
		Intern();
		
		// Copy Constructor
		Intern(const Intern& other);
		
		// Copy Assignment Operator
		Intern& operator=(const Intern& other) = delete;
		
		// Destructor
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);

};


#endif
