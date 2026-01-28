#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
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
