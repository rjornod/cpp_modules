#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form():_name("Default Form"), _isSigned(false), _gradeToSign(50), _gradeToExecute(5) 
{
    std::cout << "Form default constructor called" << std::endl;
}

//Parameterized Constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other):_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    std::cout << "Form copy constructor called" << std::endl;
}

// Destructor
Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSignedInfo() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}
const char* Form::GradeTooHighException::what() const noexcept
{
	return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
		return "the grade is too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& output_stream, const Form& form)
{
	output_stream	<< BLUE << " Form name: " << WHITE << form.getName()
					<< BLUE << "\n Is form Signed: " << WHITE << form.getSignedInfo()
					<< BLUE << "\n Grade to Sign: " << WHITE << form.getGradeToSign()
					<< BLUE << "\n Grade to Execute: " << WHITE << form.getGradeToExecute() 
					<< std::endl;

	return output_stream;
}
