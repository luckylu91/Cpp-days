#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const & other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Assignation operator called" << std::endl;
	value = other.value;
	return *this;
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member functio called" << std::endl;
	return value;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member functio called" << std::endl;
	value = raw;
}
