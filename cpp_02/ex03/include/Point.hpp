#include "../include/Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point( const float n1, const float n2 );
		Point ( const Point& copy );
		Point &operator=( const Point& overload );
		~Point();

};