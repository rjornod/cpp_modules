#include <iostream>
#include "../include/Point.hpp"

int main( void ) 
{
	//points of the triangle
	Point a( 0.0f, 0.0f );
	Point b( 5.0f, 0.0f );
	Point c( 0.0f, 5.0f );
	//points we want to know
	//	inside
	Point pointa(1.0f, 1.0f);
	Point pointb(1.0f, 2.0f);
	Point pointh(4.5f, 0.4f); 

	//	edges and vertices
	Point pointi(0.0f, 0.0f);	// vertex A
	Point pointj(5.0f, 0.0f);	// vertex B
	Point pointn(3.0f, 0.0f);	// on AB edge

	//	outside
	Point pointo(-1.0f, 1.0f);
	Point pointp(1.0f, -1.0f);
	Point pointv(1.0f, 6.0f);



	
	std::cout << std::endl <<"Point on the inside of triangle" << std::endl;
	
	std::cout << "( " << pointa.getXVal() << ", " << pointa.getYVal() << " ): "; 
	if (bsp(a,b,c,pointa) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	std::cout << "( " << pointb.getXVal() << ", " << pointb.getYVal() << " ): "; 
	if (bsp(a,b,c,pointb) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	std::cout << "( " << pointh.getXVal() << ", " << pointh.getYVal() << " ): "; 
	if (bsp(a,b,c,pointh) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;



	
	std::cout << std::endl << std::endl <<"Point on an edge or vertex" << std::endl;

	std::cout << "( " << pointi.getXVal() << ", " << pointi.getYVal() << " ): "; 
	if (bsp(a,b,c,pointi) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << "( " << pointj.getXVal() << ", " << pointj.getYVal() << " ): "; 
	if (bsp(a,b,c,pointj) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	std::cout << "( " << pointn.getXVal() << ", " << pointn.getYVal() << " ): "; 
	if (bsp(a,b,c,pointn) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	



	std::cout << std::endl << std::endl <<"Points on the outside of the triangle" << std::endl;
	
	std::cout << "( " << pointo.getXVal() << ", " << pointo.getYVal() << " ): "; 
	if (bsp(a,b,c,pointo) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	std::cout << "( " << pointp.getXVal() << ", " << pointp.getYVal() << " ): "; 
	if (bsp(a,b,c,pointp) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	
	std::cout << "( " << pointv.getXVal() << ", " << pointv.getYVal() << " ): "; 
	if (bsp(a,b,c,pointv) == true)
	 	std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}