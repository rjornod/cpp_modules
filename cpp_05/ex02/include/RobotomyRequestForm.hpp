#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

class RobotomyRequestForm
{
public:
    // Default Constructor
    RobotomyRequestForm();
    
    // Copy Constructor
    RobotomyRequestForm(const RobotomyRequestForm& other);
    
    // Copy Assignment Operator
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    
    // Destructor
    ~RobotomyRequestForm();
};

#endif
