#include "Fixed.hpp"
#include <cmath>

// DEFAULT CONSTRUCTOR
Fixed::Fixed() : _rawBits(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR
Fixed::Fixed(Fixed const & src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// INT CONSTRUCTOR
Fixed::Fixed(const int integer) : _rawBits(integer << Fixed::_fracBits)
{
//	std::cout << "Int constructor called" << std::endl;
}

// FLOAT CONSTRUCTOR
Fixed::Fixed(const float floating) : _rawBits(roundf(floating * (1 << Fixed::_fracBits)))
{
//	std::cout << "Float contructor called" << std::endl;
}

// DESTRUCTOR
Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

// COPY ASSIGNMENT OPERATOR
Fixed &	Fixed::operator=(Fixed const & rhs)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) this->_rawBits = rhs.getRawBits();
	return *this;
}

//MEMBER FUNCTIONS

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits called" << std::endl;
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

// COMPARISON OPERATORS

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->toFloat() != rhs.toFloat());
}

// ARITHMETIC OPERATORS

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

// INCREMENT AND DECREMENT OPERATORS

Fixed &	Fixed::operator++(void)
{
	*this = *this + Fixed(0.00390625f);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	cpy(*this);
	*this = *this + Fixed(0.00390625f);
	return cpy;
}

Fixed &	Fixed::operator--(void)
{
	*this = *this - Fixed(0.00390625f);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	cpy(*this);
	*this = *this - Fixed(0.00390625f);
	return cpy;
}

// MIN & MAX FUNCTIONS

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	if (a <= b) return a; else return b;
}

Fixed const &	min(Fixed const & a, Fixed const & b)
{
	if (a <= b) return a; else return b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	if (a >= b) return a; else return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b) return a; else return b;
}

// OUTPUT STREAM OPERATOR

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
