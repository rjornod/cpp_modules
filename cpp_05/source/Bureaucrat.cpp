#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat():_name("Default Bureaucrat"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name), _grade(grade)
{
	    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
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

void Bureaucrat::incGrade()
{
	int tempGrade = _grade;
	try {
		if (tempGrade - 1 < 1)
			throw 1;
		else
			_grade--;
	}
	catch (int e) {
		std::cout 	<< "Can't increment the grade further for " 
					<< BLUE <<_name << WHITE 
					<< ", it is already " << RED << _grade << WHITE << std::endl;
	}
}

void Bureaucrat::decGrade()
{
	int tempGrade = _grade;
	try {
		if (tempGrade + 1 > 150)
			throw 1;
		else
			_grade++;
	}
	catch (int e) {
		std::cout 	<< "Can't decrement the grade further for " 
					<< BLUE <<_name << WHITE 
					<< ", it is already " << RED << _grade << WHITE << std::endl;
	}

}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

//overload of the insertion operator
std::ostream& operator<<(std::ostream& output_stream, const Bureaucrat& bureaucrat)
{
	output_stream <<  bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return output_stream; //return stream for chaining
}