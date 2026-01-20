#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat():_name("Default Bureaucrat"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const noexcept 
{
		return "The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept 
{
		return "The grade is too low";
}

// Functions to increment and decrement

void Bureaucrat::incGrade()
{

	if (_grade - 1 < 1)
		throw GradeTooLowException();
	_grade--;

}

void Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooHighException();
	_grade++;

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

