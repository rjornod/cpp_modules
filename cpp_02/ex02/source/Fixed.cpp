#include "../include/Fixed.hpp"
#include <cmath>

//default destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//defualt constrcutor, doesnt take a parameter
Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

//constrcutor that takes an int as a parameter and converts it to its corresponding fixed-point value.
Fixed::Fixed( const int value )
{
	setRawBits(value << _fractBits); //same as (value * 256)
}

//constrcutor that takes a float as a parameter and converts it to its corresponding fixed-point value.
Fixed::Fixed( const float value )
{
	// roundf rounds up the value to the neares representable value. 
	// if you dont use roundf it moves the value closer to 0
	setRawBits((roundf(value * (1 << _fractBits))));
}

//copy constructor
Fixed::Fixed( const Fixed& other)
{
	setRawBits(other.getRawBits());
}

//copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

/**
 * @brief function converts a fixed point value to a float
 * 
 * the conversion is done by casting _fixedPointVal to a float and then dividing it
 * by 256.0f, a float value to avoid integer division. this preservs the factional part
 *
 * @return float 
 */
float Fixed::toFloat( void ) const
{
	return static_cast<float>(_fixedPointVal) / 256.0f;
}

/**
 * @brief function that converts the fixed-point value to an integer value.
 * 
 * Conversion is done by taking the fixed point value and dividing it by 256 (the scaling factor)
 * @return int 
 */
int Fixed::toInt( void ) const
{
	return getRawBits() / 256;
}

int Fixed::getRawBits( void ) const
{
	return _fixedPointVal;
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointVal = raw;
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed)
{
	output_stream << fixed.toFloat(); //converts fixed to a readable float
	return output_stream; //return stream for chaining
}



//this->getRawBits() referes to the value of the current object
//other.getRawBits() refers to the value of the object being compared

/**
 * 
 * The comparison operators compare the fixed point value of this and other and returns
 * true or false based on the result
 * 
 */
bool Fixed::operator!=( const Fixed& other ) const
{
	return ( this->_fixedPointVal != other._fixedPointVal );
}

bool Fixed::operator==( const Fixed& other ) const
{
	return ( this->_fixedPointVal == other._fixedPointVal );
}

bool Fixed::operator>( const Fixed& other ) const
{
	return ( this->_fixedPointVal > other._fixedPointVal );
}

bool Fixed::operator<( const Fixed &other ) const
{
	return ( this->_fixedPointVal < other._fixedPointVal );
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return ( this->_fixedPointVal >= other._fixedPointVal );
}

bool Fixed::operator<=( const Fixed &other ) const
{
	return ( this->_fixedPointVal <= other._fixedPointVal );
}


/**
 * 
 * The arithmetic operators are expected to produce a new value without modifying the original values.
 * That's why we create a new object called result which will store the new value and return it
 * 
 */

Fixed Fixed::operator+( const Fixed& other ) const
{
	Fixed result;

	result.setRawBits( this->getRawBits() + other.getRawBits() );

	return ( result );
}

Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result;

	result.setRawBits( this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator/( const Fixed& other) const
{
	return ( Fixed(this->toFloat() / other.toFloat()) );
}


Fixed Fixed::operator*( const Fixed& other ) const
{
	return ( Fixed(this->toFloat() * other.toFloat()) );

}

//pre increment overload
Fixed &Fixed::operator++()
{
	++_fixedPointVal;
	return *this;
}

//pre decrement overload
Fixed &Fixed::operator--()
{
	--_fixedPointVal;
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed copy = *this;
	++_fixedPointVal;

	return copy;
}

Fixed Fixed::operator--( int )
{
	Fixed copy = *this;
	--_fixedPointVal;

	return copy;
}

const Fixed& Fixed::min( const Fixed& first, const Fixed& second )
{
	if ( first._fixedPointVal < second._fixedPointVal )
		return first;
	else
		return second;
}

const Fixed& Fixed::min( Fixed& first, Fixed& second)
{
	if ( first._fixedPointVal < second._fixedPointVal )
		return first;
	else
		return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if ( first._fixedPointVal > second._fixedPointVal )
		return first;
	else
		return second;
}

const Fixed& Fixed::max( Fixed& first, Fixed& second)
{
	if ( first._fixedPointVal > second._fixedPointVal )
		return first;
	else
		return second;
}
