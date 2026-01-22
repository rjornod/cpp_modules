#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		// Default Constructor
		PresidentialPardonForm();

		// Parameterized Constructor
		PresidentialPardonForm::PresidentialPardonForm(const std::string target);
		
		// Copy Constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);
		
		// Copy Assignment Operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		
		// Destructor
		~PresidentialPardonForm();
};

#endif
