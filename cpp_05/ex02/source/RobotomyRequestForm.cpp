#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm ("Robotomy Request Form", 72, 45)
{
	_target = target;
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm ("Robotomy Request Form", 72, 45) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
};
