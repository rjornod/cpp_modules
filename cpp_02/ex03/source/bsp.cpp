#include "../include/Point.hpp"
//function calculates the area of a triangle, given the coordinates of its vertices
Fixed calcArea( const Point& first, const Point& second, const Point& third )
{
	Fixed av;
	Fixed bv;
	Fixed cv;

	av = ( first.getXVal() * ( second.getYVal() - third.getYVal() ) );
	bv = ( second.getXVal() * ( third.getYVal() - first.getYVal() ) );
	cv = ( third.getXVal() * ( first.getYVal() - second.getYVal() ) );

	return (av + bv + cv) / 2;
}

/**
 * 
 * a, b, c : the coordinates of the vertices of the triangle
 * point : the coordinates of the point to check
 * 
 * returns true if the point is inside the triangle and false otherwise
 * 
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = calcArea( a, b, c );
	Fixed areaABP = calcArea( a, b, point );
	Fixed areaAPC = calcArea( a, point, c );
	Fixed areaPBC = calcArea( point, b, c );

	std::cout << std::endl << "areaABC is: " << areaABC << std::endl;
	std::cout << "areaABP is: " << areaABP << std::endl;
	std::cout << "areaAPC is: " << areaAPC << std::endl;
	std::cout << "areaPBC is: " << areaPBC << std::endl;
	if ( areaABC == 0)
		return false;
	if ( areaABP == 0 || areaAPC == 0 || areaPBC == 0 )
		return false;
	if ( areaABC > 0 ) //if original area is > 0 then for a point to be inside all the areas also need to be above 0
	{
		if ( areaABP > 0 && areaAPC > 0 && areaPBC > 0) //if this is valid, the point is inside the triangle
			return true;
		else
			return false;
	}
	if ( areaABC < 0 )
	{
		if ( areaABP < 0 && areaAPC < 0 && areaPBC < 0) //if this is valid, the point is inside the triangle
			return true;
		else
			return false;
	}
	return false;
}