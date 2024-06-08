#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &	WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs) this->type = rhs.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound()
{
	std::cout << "MEOW!!" << std::endl;
}
