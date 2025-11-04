#include <iostream>
#include "../include/Point.hpp"

int main( void ) 
{
	Point a( 0.0f, 0.0f );
	Point b( 5.0f, 0.0f );
	Point c( 0.0f, 5.0f );
	Point point( 0.0f, 0.0f );

	std::cout << a.getXVal() << std::endl;
	// std::cout << a.getYVal() << std::endl;
	std::cout << b.getXVal() << std::endl;
	// std::cout << b.getYVal() << std::endl;

	//bsp(a,b,c, point);
	if (bsp(a,b,c,point) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}