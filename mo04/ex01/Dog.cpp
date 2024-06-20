#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(Dog const & src) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain;
		*this->brain = *rhs.brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound()
{
	std::cout << "WOOF!!" << std::endl;
}
