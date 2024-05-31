#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) : _value(value << Fixed::_nfb)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(value * (1 << Fixed::_nfb))
{
	std::cout << "Float constructor called" << this->_value << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs) this->_value = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)(this->_value / (1 << Fixed::_nfb));
}

int	Fixed::toInt(void) const
{
	return this->_value >> Fixed::_nfb;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
