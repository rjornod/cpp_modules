#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    // Default Constructor
    RobotomyRequestForm();

	// Parameterized Constructor
	RobotomyRequestForm(const std::string target);
    
    // Copy Constructor
    RobotomyRequestForm(const RobotomyRequestForm& other);
    
    // Copy Assignment Operator
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    
    // Destructor
    ~RobotomyRequestForm();

	void execute(Bureaucrat const &executor) const override;

};

#endif
