#include <Span.hpp>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"

int main()
{
	// CREATING A SPAN WITH SPACE FOR 5 ELEMENTS AND FILLING IT WITH DIFFERENT VALUES
	std::cout << BLUE << "\nCREATING A SPAN WITH SPACE FOR 5 ELEMENTS AND FILLING IT WITH DIFFERENT VALUES" << WHITE << std::endl;
	Span sp(5);
	sp.addNumber(120);
	sp.addNumber(0);
	sp.addNumber(170);
	sp.addNumber(10);
	sp.addNumber(100);
	
	// TRYING TO ADD ANOTHER VALUE TO AN ALREADY FILLED SPAN
	std::cout << BLUE << "TRYING TO ADD ANOTHER VALUE TO AN ALREADY FILLED SPAN" << WHITE << std::endl;
	try {
		sp.addNumber(213);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << WHITE << e.what() << std::endl;
	}
	// SHORTEST AND LONGEST SPAN TEST
	std::cout << BLUE << "\nSHORTEST AND LONGEST SPAN TEST" << WHITE <<std::endl;
	std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
	std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;

	// 	TESTING CALLING shortestSpan() and longestSpan() ON A SPAN WITH 1 ELEMENT
	std::cout << BLUE << "\nTESTING CALLING shortestSpan() and longestSpan() ON A SPAN WITH 1 ELEMENT" << WHITE << std::endl;
	Span one(1);
	try
	{
		one.shortestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << RED << "Exception: " << WHITE << e.what() << std::endl;
	}

	// USING spanFill() INSTEAD OF addNumber() TO FILL A VERY LARGE SPAN
	std::cout << BLUE << "\nUSING spanFill() INSTEAD OF addNumber() TO FILL A VERY LARGE SPAN" << WHITE << std::endl;
	Span fill(10000);
	fill.spanFill(10000);

	// TRYING TO USE spanFill() AGAIN ON THE ALREADY FILLED SPAN
	std::cout << BLUE << "\nTRYING TO USE spanFill() AGAIN ON THE ALREADY FILLED SPAN" << WHITE << std::endl;
	try 
	{
		fill.spanFill(100);
	}
	catch(std::exception &e)
	{
		std::cout << RED << "Exception: " << WHITE << e.what() << std::endl;
	}
	return 0;
}
