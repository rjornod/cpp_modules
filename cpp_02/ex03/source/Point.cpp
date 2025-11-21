#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point( const float n1, const float n2 ) : _x(n1), _y(n2) {}

Point::Point( const Point& copy ):_x(copy._x), _y(copy._y) {}

Point::~Point() {}

const Fixed& Point::getYVal() const
{
	return _y;
}

const Fixed& Point::getXVal() const
{
	return _x;
}