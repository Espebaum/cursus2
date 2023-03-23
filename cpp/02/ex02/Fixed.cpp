#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed = num << this->fraction;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed = roundf(num * 256);
}

Fixed::Fixed(const Fixed &origin) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

int	Fixed::getRawBits() const
{
	return (this->fixed);
}

float Fixed::toFloat( void ) const
{
	return((float)this->fixed / 256);
}

int Fixed::toInt( void ) const
{
	return (this->fixed >> this->fraction);
}

bool	Fixed::operator>(const Fixed &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(const Fixed &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(const Fixed &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator!=(const Fixed &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

bool	Fixed::operator==(const Fixed &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		this->fixed = ref.getRawBits();
	}
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &ref)
{
	Fixed	ret(this->toFloat() + ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &ref)
{
	Fixed	ret(this->toFloat() - ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &ref)
{
	Fixed	ret(this->toFloat() * ref.toFloat());
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &ref)
{
	Fixed	ret(this->toFloat() / ref.toFloat());
	return (ret);
}

Fixed&	Fixed::operator++()
{
	this->fixed++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this);
	this->fixed++;
	return (ret); //this is not an Rvalue
}

Fixed&	Fixed::operator--()
{
	this->fixed--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	const Fixed	ret(*this);
	this->fixed--;
	return (ret);  //this is not an Rvalue
}

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	else
		return (ref2);
}

const Fixed&	Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return (ref1);
	else
		return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return (ref1);
	else
		return (ref2);
}

const Fixed&	Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return (ref1);
	else
		return (ref2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}
