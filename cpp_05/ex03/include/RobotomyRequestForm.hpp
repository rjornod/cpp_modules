#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "../include/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		// Default Constructor
		RobotomyRequestForm(std::string target);
		
		// Copy Constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);
		
		// Copy Assignment Operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

		// Destructor
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const override;
};

#endif
