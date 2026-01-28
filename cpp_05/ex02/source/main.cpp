#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat first;
	Bureaucrat second("Roberto", 1);

	ShrubberyCreationForm test("Convict");
	PresidentialPardonForm notsigned("Murderer");
	try{
		second.getGrade();
		test.beSigned(second);
		// test.execute(second);
		test.execute(second);
		second.executeForm(test);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::NotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}


}