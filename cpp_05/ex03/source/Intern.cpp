#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

// Intern::Intern(const Intern& other)
// {

// }


Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makePresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}
struct FormMake {
    const char* name;
    AForm* (Intern::*func)(const std::string&);
};

AForm* Intern::makeForm(const std::string formName, const std::string formTarget)
{
    static const FormMake forms[] = 
	{
		{"shrubbery", &Intern::makeShrubbery}, {"robotomy",  &Intern::makeRobotomy}, {"pardon",    &Intern::makePresidential}
	};

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*forms[i].func)(formTarget);
        }
    }
    std::cerr << "Intern cannot create " << formName << " : unknown form name" << std::endl;
    return nullptr;
}
