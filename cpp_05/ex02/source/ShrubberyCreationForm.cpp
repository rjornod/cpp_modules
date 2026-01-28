#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToSign())
		throw GradeTooLowException();
};