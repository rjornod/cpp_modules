#include <Span.hpp>

int	main(void)
{
	// NORMAL SPAN
	Span span(8);
	try {
		span.addNumber(6);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(454);
		span.addNumber(5);
		span.addNumber(0);

	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl; 
	}
	std::cout << span.shortestSpan() << std::endl;

	// SPAN WITH ONE OR LESS ELEMENTS
	Span only1(1);
	try {

		std::cout << only1.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl; 
	}


}
