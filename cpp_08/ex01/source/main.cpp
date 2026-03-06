#include <Span.hpp>

int main()
{
Span sp = Span(5);
sp.addNumber(70);
sp.addNumber(20);
sp.addNumber(170);
sp.addNumber(10);
sp.addNumber(100);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
