#include "../include/whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::cout <<  RED << "INT TEST"<< WHITE << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "swaping....."<< std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::cout << "----------------------------------"<< std::endl;

std::cout << RED << "STRINGS TEST" << WHITE << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "swapping...."<< std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}