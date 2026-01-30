#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	Intern intern;
	AForm* rrf;
	Bureaucrat second("Roberto", 15);

	rrf = intern.makeForm("robotomy", "person");
	second.signForm(*rrf);
	second.executeForm(*rrf);
}