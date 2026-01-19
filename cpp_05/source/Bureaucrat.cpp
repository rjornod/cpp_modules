#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::GradeTooHighException()
{

}

void Bureaucrat::GradeTooLowException()
{

}

void Bureaucrat::incGrade()
{

}

void Bureaucrat::decGrade()
{
	int tempGrade = _grade;
	try {
		if (tempGrade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (int e) {
		std::cout << "Grade too low";
	}
	_grade++;
}