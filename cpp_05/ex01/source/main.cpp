#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	Bureaucrat first("New hire", 150);
	Bureaucrat second("President", 1);
	Form valid("TEST", 25, 20);
	
	try {
		std::cout << GREEN << "\n[Attempting to create form with grade too high (0)]" << WHITE << std::endl;
		Form invalid("Invalid", 0, 150);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << GREEN << "\n[Attempting to create form with grade too low (151)]" << WHITE << std::endl;
		Form invalid("Invalid", 151, 150);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	// try {
	// 	std::cout << GREEN << "\n[Attempting to create a Bureaucrat with grade too low]" << WHITE << std::endl;
	// 	Bureaucrat toolow("Invalid", 151);
	// }
	// catch (Bureaucrat::GradeTooLowException &e)
	// {
	// 	std::cout << e.what() << std::endl;
		
	// }

	std::cout << GREEN << "\n[Attempting to sign a form with too low of a grade]" << WHITE << std::endl;
	first.signForm(valid);

	std::cout << GREEN << "\n[Attempting to sign a form with proper grade]" << WHITE << std::endl;
	second.signForm(valid);

	std::cout << GREEN << "\n[Printing form details]" << WHITE << std::endl;
	std::cout << valid;
}