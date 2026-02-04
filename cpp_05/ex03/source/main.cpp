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
	AForm* unknown;
	Bureaucrat second("President", 1);
	Bureaucrat low("New hire", 150);

	std::cout << BLUE << "ROBOTOMY FORM TEST" << WHITE << std::endl;
	robot = intern.makeForm("robotomy", "random person");
	second.signForm(*robot);
	std::cout << YELLOW << "[Trying to execute with too low grade]" << WHITE << std::endl;
	low.executeForm(*robot);
	std::cout << YELLOW << "[Trying to execute with a high enough grade]" << WHITE << std::endl;
	second.executeForm(*robot);
	delete robot;


	std::cout << BLUE << "\nSHRUBBERY FORM TEST" << WHITE << std::endl;
	shrub = intern.makeForm("shrubbery", "yard");
	second.signForm(*shrub);
	std::cout << YELLOW << "[Trying to execute with too low grade]" << WHITE << std::endl;
	low.executeForm(*shrub);
	std::cout << YELLOW << "[Trying to execute with a high enough grade]" << WHITE << std::endl;
	second.executeForm(*shrub);
	delete shrub;

	std::cout << BLUE << "\nPARDON FORM TEST" << WHITE << std::endl;
	pardon = intern.makeForm("pardon", "murderer");
	second.signForm(*pardon);
	std::cout << YELLOW << "[Trying to execute with too low grade]" << WHITE << std::endl;
	low.executeForm(*pardon);
	std::cout << YELLOW << "[Trying to execute with a high enough grade]" << WHITE << std::endl;
	second.executeForm(*pardon);
	delete pardon;

	std::cout << BLUE << "\nUNKNOWN FORM TEST" << WHITE << std::endl;
	unknown = intern.makeForm("badname", "test");
	if (unknown)
		delete unknown;
}