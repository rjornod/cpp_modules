#include "../include/Fixed.hpp"
#include <cmath>

Fixed::~Fixed()
{
}

Fixed::Fixed()
{
    setRawBits(0);
}

Fixed::Fixed( const int value )
{
	setRawBits(value << _fractBits); //same as (value * 256)
}

Fixed::Fixed( const float value )
{
	setRawBits((roundf(value * (1 << _fractBits))));
}

Fixed::Fixed( const Fixed& other)
{
	setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(_fixedPointVal) / 256.0f;
}

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
	Fixed result;
    long first_val = static_cast<long long>(this->getRawBits()) << _fractBits;
    long second_val = static_cast<long long>(other.getRawBits());

    if (second_val == 0)
    {
        result.setRawBits(0);
        return result;
    }
    result.setRawBits(static_cast<int>(first_val / second_val));
    return result;
}


Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed	result;
    long 	temp;

	temp = static_cast<long>(this->getRawBits()) * static_cast<long>(other.getRawBits());
    temp = temp >> _fractBits;

    result.setRawBits(static_cast<int>(temp));
    return result;
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

//post increment overload
Fixed Fixed::operator++( int )
{
	Fixed copy = *this;
	++_fixedPointVal;

	return copy;
}

//post decrement overload
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

Fixed& Fixed::min( Fixed& first, Fixed& second)
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

Fixed& Fixed::max( Fixed& first, Fixed& second)
{
	if ( first._fixedPointVal > second._fixedPointVal )
		return first;
	else
		return second;
}
