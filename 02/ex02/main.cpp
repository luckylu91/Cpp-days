#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	// possibly no copy constructor due to compiler optimisation
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 1.25f ) / Fixed( 5 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << c << std::endl;
	return 0;
}
