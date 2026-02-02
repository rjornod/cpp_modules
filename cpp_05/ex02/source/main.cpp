#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat first("GradeTooLow", 150);
	Bureaucrat second("Roberto", 1);

	RobotomyRequestForm test("Convict");
	ShrubberyCreationForm shub("yard");
	PresidentialPardonForm pardon("Murderer");
	std::cout << BLUE << "PRESIDENTIAL PARDON TESTS" << WHITE << std::endl;
	try{
		std::cout << GREEN << "\n [Trying to sign with grade too low]" << WHITE << std::endl;
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << pardon.getGradeToSign() << " to be signed" << std::endl;
		pardon.beSigned(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE  << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to execute without the form being signed]" << WHITE << std::endl;
		pardon.execute(first);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to excute with too low of a grade]" << WHITE << std::endl;
		pardon.beSigned(second);
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << pardon.getGradeToExecute() << " to be executed" << std::endl;
		pardon.execute(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	std::cout << GREEN << "\n [Trying to sign and execute the form correctly]" << WHITE << std::endl;
	pardon.beSigned(second);
	std::cout << "Bureaucrats grade is " << second.getGrade() << ". The form requires grade " << pardon.getGradeToExecute() << " to be executed" << std::endl;
	pardon.execute(second);

	std::cout << BLUE << "\n\nROBOTOMY REQUEST TESTS" << WHITE << std::endl;
	try{
		std::cout << GREEN << "\n [Trying to sign with grade too low]" << WHITE << std::endl;
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << test.getGradeToSign() << " to be signed" << std::endl;
		test.beSigned(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE  << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to execute without the form being signed]" << WHITE << std::endl;
		test.execute(first);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to excute with too low of a grade]" << WHITE << std::endl;
		test.beSigned(second);
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << test.getGradeToExecute() << " to be executed" << std::endl;
		test.execute(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	std::cout << GREEN << "\n [Trying to sign and execute the form correctly]" << WHITE << std::endl;
	test.beSigned(second);
	std::cout << "Bureaucrats grade is " << second.getGrade() << ". The form requires grade " << test.getGradeToExecute() << " to be executed" << std::endl;
	test.execute(second);

	std::cout << BLUE << "\n\nSHRUBBERY CREATION TESTS" << WHITE << std::endl;
	try{
		std::cout << GREEN << "\n [Trying to sign with grade too low]" << WHITE << std::endl;
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << shub.getGradeToSign() << " to be signed" << std::endl;
		shub.beSigned(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE  << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to execute without the form being signed]" << WHITE << std::endl;
		shub.execute(first);
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	try{
		std::cout << GREEN << "\n [Trying to excute with too low of a grade]" << WHITE << std::endl;
		shub.beSigned(second);
		std::cout << "Bureaucrats grade is " << first.getGrade() << ". The form requires grade " << shub.getGradeToExecute() << " to be executed" << std::endl;
		shub.execute(first);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << "ERROR: " << WHITE << e.what() << std::endl;
	}
	std::cout << GREEN << "\n [Trying to sign and execute the form correctly]" << WHITE << std::endl;
	shub.beSigned(second);
	std::cout << "Bureaucrats grade is " << second.getGrade() << ". The form requires grade " << shub.getGradeToExecute() << " to be executed" << std::endl;
	shub.execute(second);
}