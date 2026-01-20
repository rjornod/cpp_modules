#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat first;
	
	Bureaucrat second("Roberto", 1);
	std::cout << second.getName() << std::endl;
	std::cout << second.getGrade() << std::endl;
	
	std::cout << GREEN << "INCREMENT AND DECREMENT EDGE CASES" << WHITE << std::endl;
	std::cout << RED << "/ Trying to decrement a grade that is already 150" << WHITE << std::endl;
	try {
		
		first.decGrade(); // gade is already 150
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << RED << "\n / Trying to increment a grade that is already 1" << WHITE << std::endl;
	try {
		second.incGrade(); // gade is already 1
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << RED << "\n / Trying to create a bureaucrat with an invalid grade" << WHITE << std::endl;
	try {
		Bureaucrat third("Fail", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << GREEN << "NORMAL INCREMENT AND DECREMENT" << WHITE << std::endl;
	first.incGrade();
	second.decGrade();
	std::cout << "Second " << second << std::endl;
	std::cout << "First " << first << std::endl;

}