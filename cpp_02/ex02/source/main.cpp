#include <iostream>
#include "../include/Fixed.hpp"

int main( void ) {
Fixed a(1);
Fixed b(2);

if (a != b)
	std::cout << "different" << std::endl;
else
	std::cout << "not different" << std::endl;

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