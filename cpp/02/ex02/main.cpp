#include "Fixed.hpp"

int main( void ) 
{
	std::cout << BOLDWHITE << "------------------------------------------" << std::endl;
	std::cout << BOLDCYAN;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); // Fixed(float), Fixed(int) is Rvalue

	std::cout << BOLDWHITE << "------------------------------------------" << std::endl;
	std::cout << GREEN;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << BOLDWHITE << "------------------------------------------" << std::endl;
	std::cout << RED;
	return 0;
}
