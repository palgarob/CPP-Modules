#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor was called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap " << this->_name << " was constructed." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "FragTrap " << this->_name << " was copied." << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " was destroyed." << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " highfives everybody." << std::endl;
}
