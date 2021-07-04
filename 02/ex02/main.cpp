#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	std::cout << "a = Fixed(0)" << std::endl;
	Fixed const b( Fixed( 5.05f ) );
	std::cout << "b = Fixed( Fixed( 5.05f ) ) = " << b << std::endl;
	Fixed const c( Fixed( 1.25f ) / Fixed( 5 ) );
	std::cout << "c = Fixed( Fixed( 1.25f ) / Fixed( 5 ) ) = " << c << std::endl << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl << std::endl;

	a.setRawBits(0);
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max (a, b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min (a, b) = " << Fixed::min( a, b ) << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	return 0;
}
