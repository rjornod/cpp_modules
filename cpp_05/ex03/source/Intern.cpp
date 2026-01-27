#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/Intern.hpp"

Intern::Intern()
{
std::cout << "Intern Constructor called";
}

Intern::Intern(const Intern& other)
{

}

Intern& Intern::operator=(const Intern& other)
{

}

Intern::~Intern()
{
	std::cout << "Intern destructor called";

}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	switch (form)
	{
	case constant expression:
		/* code */
		break;
	
	default:
		break;
	}
	std::cout << "test";
}