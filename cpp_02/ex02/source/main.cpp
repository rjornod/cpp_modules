#include <iostream>
#include "../include/Fixed.hpp"

#include <iomanip>

int main( void ) 
{
	//Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//std::cout << a << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;

	// std::cout << "______ INCREMENT OVERLOADS ______" << std::endl;
	// std::cout << "a value: " << a << std::endl;
	// std::cout << "Pre increment (++a): " << ++a << std::endl;
	// std::cout << "a value: " << a << std::endl;
	// std::cout << "Post increment (a++): " << a++ << std::endl;
	// std::cout << "a value: " << a << std::endl;
	// std::cout << "b value: "<< b << std::endl;
	// std::cout << "Pre decrement (--b): " << --b << std::endl;
	// std::cout << "b value: " << b << std::endl;
	// std::cout << "Post decrement (b--): " << b-- << std::endl;
	// std::cout << "b value: " << b << std::endl;

	Fixed b(4);
	Fixed a(10.5f);
	const Fixed c(10);
	const Fixed d(2);
	std::cout << std::endl << "______ ARITHMETIC OVERLOADS ______" << std::endl;
	std::cout << "Subtraction (" << a << " - " << b << "): " << a - b << std::endl;
	std::cout << "Addition (" << a << " + " << b << "): " << a + b << std::endl;
	std::cout << "Multplication (" << a << " * " << b << "): " << a * b << std::endl;
	std::cout << "Division (" << a << " / " << b << "): " << a / b << std::endl;

	std::cout << std::endl << "______ MAX AND MIN ______" << std::endl;
	std::cout << "Max: (" << a << ", " << b << "): " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: (" << a << ", " << b << "): " << Fixed::min( a, b ) << std::endl;
	std::cout << "Const Max: (" << c << ", " << d << "): " << Fixed::max( c, d ) << std::endl;
	std::cout << "Const Min: (" << c << ", " << d << "): " << Fixed::min( c, d ) << std::endl;

	std::cout <<  std::endl << "______ COMPARISON OVERLOADS ______" << std::endl;
	if (a <= b)
		std::cout << "a (" << a << ")" << " is less or equal than b (" << b << ")" << std::endl;
	else
		std::cout << "b (" << b << ")" << " is less or equal than a (" << a << ")" << std::endl << std::endl;
	if (a == b)
		std::cout << "a (" << a << ")" << " is equal to b (" << b << ")" << std::endl;
	else
		std::cout << "b (" << b << ")" << " is not equal to a (" << a << ")" << std::endl << std::endl;
	if (a >= b)
		std::cout << "a (" << a << ")" << " is bigger or equal to b (" << b << ")" << std::endl;
	else
			std::cout << "b (" << b << ")" << " is not bigger or equal to a (" << a << ")" << std::endl << std::endl;
	
	return 0;
}