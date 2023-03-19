#include "Fixed.hpp"

int main( void ) 
{
	std::cout << BLUE;
	Fixed a;

	std::cout << YELLOW;
	Fixed const b( 10 );

	std::cout << CYAN;
	Fixed const c( 42.42f );
	
	std::cout << MAGENTA;
	Fixed const d( b );

	std::cout << GREEN;
	a = Fixed( 1234.4321f );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << RED;
	return 0;
}
