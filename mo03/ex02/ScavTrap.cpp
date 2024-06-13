#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "Scavtrap " << this->_name << " was created with the name constructor." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap()
{
	*this = src;
	std::cout << "Scavtrap " << this->_name << " was created with the copy constructor." << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
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

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap " << this->_name << " was destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy != 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't attack because it has no energy left." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now on gatekeeper mode" << std::endl;
}
