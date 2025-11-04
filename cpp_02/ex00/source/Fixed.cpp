#include "../include/Fixed.hpp"

Fixed::Fixed()	
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Copy assignment operator replaces the contents of an existing object
//original object *this (left side of the =), other is the copy object(right side of =)
Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// self assignment check, if this equals copy both will point to the same memory address
	//could cause problems if memory was allocated
	
	if (this != &other)
		setRawBits(other.getRawBits());

	//we return *this (a reference to the original object) to allow for assignment chaining
	//it enables experssions like a = b = c;
	return *this;
}

//getRawBits gets the raw value of the fixed point number in the original object
//copy constructor creates a new object as a copy of an existing object
//setRawBits sets the raw value of the fixed point number into the new object
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(copy.getRawBits());
	
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}