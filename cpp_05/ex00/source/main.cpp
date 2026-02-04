#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat first("New hire", 150);
	std::cout << "Bureaucreats name: " << GREEN << first.getName() << WHITE << std::endl;
	std::cout << "Bureaucrats grade: " << first.getGrade() << WHITE << std::endl;
	Bureaucrat second("President", 1);
	std::cout << "\nBureaucreats name: " << GREEN << second.getName() << WHITE << std::endl;
	std::cout << "Bureaucrats grade: " << second.getGrade() << WHITE << std::endl;
	
	std::cout << GREEN << "\nINCREMENT AND DECREMENT EDGE CASES" << WHITE << std::endl;
	std::cout << YELLOW << "[Trying to decrement New hire's grade (150) ]" << WHITE << std::endl;
	try {
		
		first.decGrade(); // gade is already 150
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "\n[Trying to increment Presidents grade (1) ]" << WHITE << std::endl;
	try {
		second.incGrade(); // gade is already 1
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
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