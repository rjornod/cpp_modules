#include <iostream>
#include "../include/Point.hpp"

int main( void ) 
{
	Point a(2,4);
	Point b(3,0);
	Point c(1,1);
	Point point(1,0);

	std::cout << a.getX() << std::endl;
	// std::cout << a.getY() << std::endl;
	std::cout << b.getX() << std::endl;
	// std::cout << b.getY() << std::endl;

	bsp(a,b,c, point);
	// if (bsp(a,b,c,point) == true)
	// 	std::cout << "True" << std::endl;
	// else
	// 	std::cout << "False" << std::endl;

	return 0;
}