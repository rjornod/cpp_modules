#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <fstream>  

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("Robotomy Request Form", 145, 137) {
	_target = target;    
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm ("Robotomy Request Form", 145, 137) {
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
	std::string title = _target + "_shrubbery";
	std::ofstream outfile (title);
	outfile << "tree" << std::endl;

};