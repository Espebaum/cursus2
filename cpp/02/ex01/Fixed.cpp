#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed = num;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = num;
}

Fixed::Fixed(const Fixed &origin) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->fixed = ref.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

float	toFloat()
{
	std::cout << "";
	return (1);
}

int	toInt()
{
	std::cout << "";
	return (1);
}
