#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat first;
	Bureaucrat second("Roberto", 50);
	Form valid;
	
	try {
		std::cout << "Attempting to create form with grade too high" << std::endl;
		Form invalid("Name", 0, 150);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Attempting to create a Bureaucrat with grade too low" << std::endl;
		Bureaucrat toolow("Invalid", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Attempting to sign a form without proper grade" << std::endl;
	second.signForm(valid);


	std::cout << valid;

}