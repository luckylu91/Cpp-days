#pragma once
#include <iostream>

class Fixed
{
private:
	int	value;
	static int const BINARY_POINT_POSITION = 8;
public:
	Fixed();
	Fixed(Fixed const & other);
	Fixed & operator=(Fixed const & other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed(int const val_int);
	Fixed(float const val_flt);
	int toInt( void ) const;
	float toFloat( void ) const;
	int getBinaryPointPosition( void ) const;

	//TODO
	bool operator>(Fixed const &) const;
	bool operator<(Fixed const &) const;
	bool operator>=(Fixed const &) const;
	bool operator<=(Fixed const &) const;
	bool operator==(Fixed const &) const;
	bool operator!=(Fixed const &) const;
	Fixed operator+(Fixed const &) const;
	Fixed operator-(Fixed const &) const;
	Fixed operator/(Fixed const &) const;
	Fixed operator*(Fixed const &) const;
	//TODO
};
std::ostream & operator<<(std::ostream & os, Fixed const & fix);
