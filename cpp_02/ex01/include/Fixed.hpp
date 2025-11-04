#include <iostream>

/**
 * @brief _fractBits = 8 means the lower 8 bits store the fractional part. the remaining bits store the integer part. 
 * 
 * it acts as a scaling factor: rawValue = real_value * 256. 
 * 
 * Exampled:
 * 	real value = 1.0
 * 	gets store in rawValue as = 256
 * 
 * 	real value = 2.0
 * 	stores in rawValue as = 512
 * 
 * 	real value = 0.25
 * 	stored in rawValue as = 64
 */
class Fixed {
	private:
		int	_fixedPointVal;
		static const int _fractBits = 8; //scaling factor, 2^8 = 256
	public:

		Fixed(); //default constructor. initializes _value to 0
        Fixed(const int value); //parameterized constructor, initializes _value to an int
        Fixed(const float value);//initializes _value to a float
		Fixed(const Fixed& copy); //copy constructor
		Fixed &operator=(const Fixed& overload);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
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
