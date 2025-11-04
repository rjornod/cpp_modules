#include <iostream>

class Fixed {
	private:
		int	_value;
		static const int _fract_bits = 8;
	public:

		Fixed(); //default constructor. initializes _value to 0
		Fixed(const Fixed& copy); //copy constructor
		Fixed &operator=(const Fixed& overload);
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
