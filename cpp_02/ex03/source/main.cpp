#include <iostream>
#include "../include/Point.hpp"

int main( void ) 
{
	Point a( 0.0f, 0.0f );
	Point b( 5.0f, 0.0f );
	Point c( 0.0f, 5.0f );
	Point point( 1.0f, 2.0f );
	//inside
	Point pointa(1.0f, 1.0f);   // 1 + 1 = 2
	Point pointb(1.0f, 2.0f);  // 3
	Point pointc(2.0f, 2.0f);   // 4
	Point pointd(3.0f, 1.0f);   // 4
	Point pointe(0.1, 0.1f);   // 0.2
	Point pointf(2.5f, 1.0f);   // 3.5
	Point pointg(0.5f, 4.0f);   // 4.5
	Point pointh(4.5f, 0.4f);   // 4.9

	//edges and vertices
	Point pointi(0.0f, 0.0f);	// vertex A
	Point pointj(5.0f, 0.0f);	// vertex B
	Point pointk(0.0f, 5.0f);	// vertex C
	Point pointl(2.5f, 2.5f);	// on hypotenuse x+y = 5
	Point pointm(0.0f, 3.0f);	// on AC edge
	Point pointn(3.0f, 0.0f);	// on AB edge

	//outside
	Point pointo(-1.0f, 1.0f);	// x < 0
	Point pointp(1.0f, -1.0f);	// y < 0
	Point pointq(4.9999999999f, 0.0000000001f);
	Point pointr(5.0f, 1.0f);	// 6 > 5
	Point points(4.0f, 2.0f);	// 6 > 5
	Point pointt(2.6f, 2.6f);	// 5.2 > 5
	Point pointu(6.0f, 0.0f);	// outside on x axis
	Point pointv(90.0f, 6.0f);	// outside on y axis 

	std::cout << std::endl <<"Point on the inside of triangle" << std::endl;

	if (bsp(a,b,c,point) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointa) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointb) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointc) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointd) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointe) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointf) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointg) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointh) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	std::cout << std::endl << std::endl <<std::endl <<"Point on an edge or vertex" << std::endl;

	if (bsp(a,b,c,pointi) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointj) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointk) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointl) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointm) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointn) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
		std::cout << std::endl << std::endl << std::endl <<"Points on the outside of the triangle" << std::endl;
	
	if (bsp(a,b,c,pointo) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointp) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointq) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointr) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,points) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointt) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointu) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	if (bsp(a,b,c,pointv) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}