#include "../include/Fixed.hpp"
#include <cmath>

//default destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//defualt constrcutor, doesnt take a parameter
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

//constrcutor that takes an int as a parameter and converts it to its corresponding fixed-point value.
Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _fractBits); //same as (value * 256)
}

//constrcutor that takes a float as a parameter and converts it to its corresponding fixed-point value.
Fixed::Fixed( const float value )
{
 std::cout << "Float constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(value * 256)));
}

//copy constructor
Fixed::Fixed( const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy.getRawBits());
}

//copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assigment operator called" << std::endl;
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
	return _fixedPointVal / 256;
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