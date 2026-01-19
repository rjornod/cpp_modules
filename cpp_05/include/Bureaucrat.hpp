#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		// Default Constructor
		Bureaucrat();

		// Parameterized Constructor
		Bureaucrat(const std::string _name, int _grade);
		
		// Copy Constructor
		Bureaucrat(const Bureaucrat& other);
		
		// Copy Assignment Operator
		Bureaucrat& operator=(const Bureaucrat& other);
		
		// Destructor
		~Bureaucrat();

		std::string getName();
		int getGrade();
		void incGrade();
		void decGrade();
		
};

#endif
