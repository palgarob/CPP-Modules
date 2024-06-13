#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _rawBits(integer << Fixed::_fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating) : _rawBits(roundf(floating * (1 << Fixed::_fracBits)))
{
	std::cout << "Float contructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//MEMBER FUNCTIONS

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)(this->getRawBits())/(1 << Fixed::_fracBits);
}

int	Fixed::toInt(void) const
{
	return this->getRawBits() >> Fixed::_fracBits;
}

// OUTPUT STREAM OVERLOAD
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
