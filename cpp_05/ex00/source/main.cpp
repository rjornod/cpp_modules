#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat first;
	
	Bureaucrat second("Roberto", 1);
	std::cout << second.getName() << std::endl;
	std::cout << second.getGrade() << std::endl;
	
	std::cout << GREEN << "INCREMENT AND DECREMENT EDGE CASES" << WHITE << std::endl;
	std::cout << YELLOW << "[Trying to decrement a grade that is already 150]" << WHITE << std::endl;
	try {
		
		first.decGrade(); // gade is already 150
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n [Trying to increment a grade that is already 1]" << WHITE << std::endl;
	try {
		second.incGrade(); // gade is already 1
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << GREEN << "\nBUREAUCRAT CREATION WITH INVALID GRADES" << WHITE << std::endl;
	std::cout << YELLOW << "[Trying to create a bureaucrat with a grade below 150]" << WHITE << std::endl;
	try {
		Bureaucrat third("Fail", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n[Trying to create a bureaucrat with a grade above 1]" << WHITE << std::endl;
	try {
		Bureaucrat third("Fail", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << GREEN << "\nNORMAL INCREMENT AND DECREMENT" << std::endl;
	std::cout << BLUE << "Before decrement: " << WHITE << second << WHITE << std::endl;
	std::cout << BLUE << "Before increment: " << WHITE << first << std::endl;
	std::cout << RED << "\n... incrementing and decrementing ...\n" << WHITE << std::endl;
	first.incGrade();
	second.decGrade();
	std::cout << BLUE << "After decrement: " << WHITE << second << std::endl;
	std::cout << BLUE << "After increment: " << WHITE << first << std::endl;

}