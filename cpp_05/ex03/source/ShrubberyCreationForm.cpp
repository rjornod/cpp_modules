#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <fstream>  

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("Robotomy Request Form", 145, 137), _target(target) {   
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm ("Robotomy Request Form", 145, 137), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::string title = _target + "_shrubbery";
	std::ofstream outfile (title);
	outfile << "        *        " << std::endl;
	outfile << "       ***       " << std::endl;
	outfile << "      *****      " << std::endl;
	outfile << "     *******     " << std::endl;
	outfile << "    *********    " << std::endl;
	outfile << "   ***********   " << std::endl;
	outfile << "  *************  " << std::endl;
	outfile << " *************** " << std::endl;
	outfile << "*****************" << std::endl;
	outfile << "       |||        " << std::endl;
	outfile << "       |||        " << std::endl;

};