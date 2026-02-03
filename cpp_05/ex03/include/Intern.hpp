#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# define RED "\033[1;31m"
# define WHITE "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

/*
		The intern class does not hold any variables with data we don't need the copy constructor
	or copy assignment operator.
		This means we can delete them since there is no data to copy.
*/
class Intern
{
	private:
		AForm* makePresidential(const std::string& target);
		AForm* makeShrubbery(const std::string& target);
		AForm* makeRobotomy(const std::string& target);

	public:
		// Default Constructor
		Intern();
		
		// Copy Constructor
		Intern(const Intern& other) = delete;
		
		// Copy Assignment Operator
		Intern& operator=(const Intern& other) = delete;
		
		// Destructor
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
