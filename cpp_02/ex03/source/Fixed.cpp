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
	setRawBits(static_cast<int>(roundf(value * 256)));
}

Fixed::Fixed( const Fixed& copy)
{
	setRawBits(copy.getRawBits());
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

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedPointVal != other._fixedPointVal);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedPointVal == other._fixedPointVal);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedPointVal > other._fixedPointVal);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointVal < other._fixedPointVal);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedPointVal >= other._fixedPointVal);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointVal <= other._fixedPointVal);
}


/**
 * 
 * The arithmetic operators are expected to produce a new value without modifying the original values.
 * That's why we create a new object called result which will store the new value and return it
 * 
 */

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	return Fixed(this->toFloat() - other.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}


Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed &Fixed::operator++()
{
	++_fixedPointVal;
	return *this;
}

Fixed &Fixed::operator--()
{
	--_fixedPointVal;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	++_fixedPointVal;

	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	--_fixedPointVal;

	return copy;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
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
