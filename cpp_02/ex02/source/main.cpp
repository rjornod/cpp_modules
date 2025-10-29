#include <iostream>
#include "../include/Fixed.hpp"

int main( void ) 
{
	Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed b(2.02f);
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

	return 0;
}