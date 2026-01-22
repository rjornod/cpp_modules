#include "PresidentialPardonForm.hpp"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

//Paremeterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target) {
	_target = target;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
