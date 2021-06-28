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
};
