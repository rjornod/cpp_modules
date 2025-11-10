#include <iostream>
#include "../include/Fixed.hpp"

#include <iomanip>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed b(255.12312344f);
	std::cout << "[a] value: " << a << std::endl;
	std::cout << "Pre increment: " << ++a << std::endl;
	std::cout << "[a] value: " << a << std::endl;
	std::cout << "Post increment: " << a++ << std::endl;
	std::cout << "[a] value: " << a << std::endl;
	std::cout << "[b] value: "<< b << std::endl;
	// a = 1;
	// if (a <= b)
	// 	std::cout << "a is less or equal than b" << std::endl;
	// else
	// 		std::cout << "b is less or equal than a" << std::endl;
	std::cout << "Subtraction: " << a - b << std::endl;
	std::cout << "Addition: " << a + b << std::endl;
	std::cout << "Multplication: " << a * b << std::endl;
	std::cout << "Division: " << a / b << std::endl;
	std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: " << Fixed::min( a, b ) << std::endl;

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
	return 0;
}