#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val_int) : value(val_int << Fixed::BINARY_POINT_POSITION)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val_flt) : value(roundf(val_flt * (1 << Fixed::BINARY_POINT_POSITION)))
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int Fixed::toInt( void ) const
{
	return value >> Fixed::BINARY_POINT_POSITION;
}

float Fixed::toFloat( void ) const
{
	return (float)value / (1 << Fixed::BINARY_POINT_POSITION);
}

std::ostream & operator<<(std::ostream & os, Fixed const & fix)
{
	os << fix.toFloat();
	return os;
}

bool Fixed::operator>(Fixed const & other) const
{
	return value > other.value;
}

bool Fixed::operator<(Fixed const & other) const
{
	return value < other.value;
}

bool Fixed::operator>=(Fixed const & other) const
{
	return value >= other.value;
}

bool Fixed::operator<=(Fixed const & other) const
{
	return value <= other.value;
}

bool Fixed::operator==(Fixed const & other) const
{
	return value == other.value;
}

bool Fixed::operator!=(Fixed const & other) const
{
	return value != other.value;
}


Fixed Fixed::operator+(Fixed const & other) const
{
	return value + other.value;
}

Fixed Fixed::operator-(Fixed const & other) const
{
	return value - other.value;
}

Fixed Fixed::operator/(Fixed const & other) const
{
	Fixed	res;
	int		rawBits = (((long)value) << Fixed::BINARY_POINT_POSITION) \
		/ (long)other.value;

	res.setRawBits(rawBits);
	return res;
}

Fixed Fixed::operator*(Fixed const & other) const
{
	Fixed	res;
	int		rawBits = (((long)value * (long)other.value) \
		>> Fixed::BINARY_POINT_POSITION);

	res.setRawBits(rawBits);
	return res;
}


Fixed & Fixed::operator++()
{
	value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	++(*this);
	return copy;
}

Fixed & Fixed::operator--()
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	--(*this);
	return copy;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a <= b)
		return a;
	else
		return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a >= b)
		return a;
	else
		return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b)
		return a;
	else
		return b;
}

