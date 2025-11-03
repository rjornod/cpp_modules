#include "../include/Point.hpp"

float sign(  Point const a, Point const b, Point const c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY());
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
	
}