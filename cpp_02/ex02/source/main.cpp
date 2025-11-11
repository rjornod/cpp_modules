#include <iostream>
#include "../include/Fixed.hpp"

#include <iomanip>

int main( void ) 
{
	Fixed a(0);
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed b(2.5f);
	std::cout << "______ INCREMENT OVERLOADS ______" << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "Pre increment (++a): " << ++a << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "Post increment (a++): " << a++ << std::endl;
	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: "<< b << std::endl;
	std::cout << "Pre decrement (--b): " << --b << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "Post decrement (b--): " << b-- << std::endl;
	std::cout << "b value: " << b << std::endl;

	a = 0.1f;
	b = 25.5f;
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
		std::cout << "b (" << a << ")" << " is less or equal than a (" << a << ")" << std::endl << std::endl;
	if (a == b)
		std::cout << "a (" << a << ")" << " is equal to b (" << b << ")" << std::endl;
	else
		std::cout << "b (" << a << ")" << " is not equal to a (" << a << ")" << std::endl << std::endl;
	if (a >= b)
		std::cout << "a (" << a << ")" << " is bigger or equal to b (" << b << ")" << std::endl;
	else
			std::cout << "b (" << a << ")" << " is not bigger or equal to a (" << a << ")" << std::endl << std::endl;
	// Fixed a;
	// Fixed b;
	// Fixed c;
	// Fixed d(1.8f);
	// Fixed const e( 42.42f );
	// a.setRawBits(2147483632);
	// b.setRawBits(1);
	// c.setRawBits(-2147483648);
	// d.setRawBits(2147483633);
	
	//std::cout << std::setprecision(8) << a << std::endl;
	// std::cout << a.getRawBits() << std::endl;
	//a = a + b;
	//d = d + b;
	// std::cout << "e is " << e << std::endl;
	// std::cout << "d is " << d.toInt() << std::endl;
	// std::cout << "the value of a is : "  << a << std::endl;
	// std::cout << "the value of d is : "  << d << std::endl;
	// std::cout << "a raw=" << a.getRawBits() << " a=" << std::fixed << std::setprecision(8) << a.toFloat() << '\n';
	// std::cout << "d raw=" << d.getRawBits() << " d=" << std::fixed << std::setprecision(8) << d.toFloat() << '\n';

	// std::cout << std::setprecision(8) << a << std::endl;
	// std::cout << std::setprecision(8) << b << std::endl;
	// std::cout << std::setprecision(8) << c << std::endl;
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}