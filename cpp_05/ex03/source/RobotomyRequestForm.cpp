#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm ("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm ("Robotomy Request Form", 72, 45), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
    srand(time(0));
    int num = rand() % 2 + 1;
    std::cout << "*DRILLING NOISES*" << std::endl;
    if (num == 1)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "The robotomization has failed!" << std::endl;
};
