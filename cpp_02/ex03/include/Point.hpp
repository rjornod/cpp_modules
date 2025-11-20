#include "../include/Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();                                                                                                                                                                                                                                                                                                                                                                                                                              
		Point( const float n1, const float n2 );
		Point ( const Point& copy );
		Point &operator=( const Point& overload ) = delete; //because Point store coordinates as const Fixed members, doing so after construction is not possible. delete tells the compiler this assigment is disabled a = b is not possible and will fail at compile time 
		~Point();
		const Fixed& getXVal() const;
		const Fixed& getYVal() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);