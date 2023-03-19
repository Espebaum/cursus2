#include "Fixed.hpp"

int main( void ) 
{
	//define color
	std::cout << BLUE;
	Fixed a;

	//define color	
	std::cout << GREEN;
	Fixed b( a );

	//define color
	std::cout << YELLOW;
	Fixed c;
	c = b;

	//define color
	std::cout << CYAN;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	//define color
	std::cout << RED;
	return 0;
}
