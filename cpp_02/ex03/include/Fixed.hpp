#include <iostream>


class Fixed {
	private:
		int	_fixedPointVal;
		static const int _fractBits = 8; //scaling factor, 2^8 = 256
	public:

		Fixed(); //default constructor. initializes _value to 0
        Fixed( const int value ); //parameterized constructor, initializes _value to an int
        Fixed( const float value );//initializes _value to a float
		Fixed( const Fixed& copy ); //copy constructor
		Fixed &operator=( const Fixed& overload );
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

		//these member functions will compare *this with other and return true or false
		bool operator==( const Fixed& other ) const;
		bool operator>( const Fixed& other ) const;
		bool operator<( const Fixed& other ) const;
		bool operator!=( const Fixed& other ) const;
		bool operator<=( const Fixed& other ) const;
		bool operator>=( const Fixed& other ) const;

		//Add other to the current object without changing either, and return a new Fixed object as the result
		Fixed operator+( const Fixed& other ) const;
		Fixed operator*( const Fixed& other ) const;
		Fixed operator-( const Fixed& other ) const;
		Fixed operator/( const Fixed& other ) const;

		Fixed& operator++(); //pre increment
		Fixed& operator--(); //pre decrement
		Fixed operator++(int); //int is the differentiator between pre increment and post decrement
		Fixed operator--(int); //post decrement

		static const Fixed& min( const Fixed& first, const Fixed& second );
		static const Fixed& min( Fixed& first, Fixed& second );
		static const Fixed& max( const Fixed& first, const Fixed& second );
		static const Fixed& max( Fixed& first, Fixed& second );
};

/**
 * @brief Non member function that defines how Fixed objects are printed to output streams
 * 
 * It's what makes std::cout << FixedObject work
 * 
 * @param output_stream reference to the output stream
 * @param fixed the fixed object to be printed (passed by const reference)
 * @return std::ostream& - returns the same stream to allow chaining
 */
std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed);
