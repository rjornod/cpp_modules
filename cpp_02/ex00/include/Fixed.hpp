#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_value;
		static const int _fract_bits = 8;
	public:

		Fixed(); //default constructor. initializes _value to 0
		Fixed(const Fixed& copy); //copy constructor, constructs a new object as a copy of an existing one. The original object is not modified.
		Fixed &operator=(const Fixed& overload); // copy assignment operator, assigns to an existing object; the left-hand object is modified to match the right-hand object. Should handle self-assignment and return *this.
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif