#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

// Default Constructor
AForm::AForm():_name("Default AForm"), _isSigned(false), _gradeToSign(50), _gradeToExecute(5) 
{
  //  std::cout << "AForm default constructor called" << std::endl;
}

//Parameterized Constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other):_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
 //   std::cout << "AForm copy constructor called" << std::endl;
}

// Destructor
AForm::~AForm() {
 //   std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSignedInfo() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}
const char* AForm::GradeTooHighException::what() const noexcept
{
	return "the grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
		return "the grade is too low";
}

const char* AForm::NotSignedException::what() const noexcept
{
	return "form not signed";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (getSignedInfo() != 1)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
} 

std::ostream& operator<<(std::ostream& output_stream, const AForm& form)
{
	output_stream	<< BLUE << " Form name: " << WHITE << form.getName()
					<< BLUE << "\n Is form Signed: " << WHITE << form.getSignedInfo()
					<< BLUE << "\n Grade to Sign: " << WHITE << form.getGradeToSign()
					<< BLUE << "\n Grade to Execute: " << WHITE << form.getGradeToExecute() 
					<< std::endl;

	return output_stream;
}
