#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	Intern intern;
	AForm* robot;
	AForm* shrub;
	AForm* pardon;
	AForm* badName;
	Bureaucrat second("Roberto", 1);
	Bureaucrat low("GradeTooLow", 150);

	std::cout << BLUE << "ROBOTOMY FORM TEST" << WHITE << std::endl;
	robot = intern.makeForm("robotomy", "random person");
	second.signForm(*robot);
	low.executeForm(*robot);
	second.executeForm(*robot);
	delete robot;


	std::cout << BLUE << "\nSHRUBBERY FORM TEST" << WHITE << std::endl;
	shrub = intern.makeForm("shrubbery", "yard");
	second.signForm(*shrub);
	low.executeForm(*shrub);
	second.executeForm(*shrub);
	delete shrub;

	std::cout << BLUE << "\nPARDON FORM TEST" << WHITE << std::endl;
	pardon = intern.makeForm("pardon", "murderer");
	second.signForm(*pardon);
	low.executeForm(*pardon);
	second.executeForm(*pardon);
	delete pardon;

	std::cout << BLUE << "\nUNKOWN FORM TEST" << WHITE << std::endl;
	badName = intern.makeForm("badname", "test");
}