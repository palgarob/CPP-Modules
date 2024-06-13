#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << name << " was created with the name constructor." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap " << src._name << " was created with the copy constructor." << std::endl;
	*this = src;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
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

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " was destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy != 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't attack because it has no energy left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_health)
		this->_health = 0;
	else
		this->_health -= amount;
	std::cout << "ClapTrap " << this->_name << " was dealt " << amount << " points of damage, leaving it with " << this->_health << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy != 0)
	{
		this->_health += amount;
		std::cout << "ClapTrap " << this->_name << " recovers " << amount << " hit points, leaving it with " << this->_health << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't recover because it has no energy left." << std::endl;

}
