#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "../include/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;

	public:
		// Default Constructor
		PresidentialPardonForm(const std::string target);
		
		// Copy Constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);
		
		// Copy Assignment Operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		
		// Destructor
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const override;
};

#endif
