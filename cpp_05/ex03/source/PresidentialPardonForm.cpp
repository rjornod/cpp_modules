#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {
  //  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon", 25, 5), _target(other._target){
 //   std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
  //  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
    if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
