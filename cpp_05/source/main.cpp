#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat first;
	Bureaucrat second("Roberto", 1);

	Bureaucrat third("Roberto", 0);

	std::cout << second.getName() << std::endl;
	std::cout << second.getGrade() << std::endl;
	
	std::cout << GREEN << "INCREMENT AND DECREMENT EDGE CASES" << WHITE << std::endl;
	first.decGrade(); // grade is already 150
	second.incGrade(); // gade is already 1
	std::cout << GREEN << "NORMAL INCREMENT AND DECREMENT" << WHITE << std::endl;
	first.incGrade();
	second.decGrade();
	std::cout << second << std::endl;
	std::cout << first << std::endl;
}