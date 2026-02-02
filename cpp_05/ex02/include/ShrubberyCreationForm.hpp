#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "../include/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		// Default Constructor
		ShrubberyCreationForm(const std::string target);

		// Copy Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		
		// Copy Assignment Operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
		
		// Destructor
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const override;
};

#endif
