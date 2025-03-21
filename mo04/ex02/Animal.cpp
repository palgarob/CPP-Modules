/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:59:54 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 20:59:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &	AAnimal::operator=(AAnimal const & rhs)
{
	if (this != &rhs) this->type = rhs.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->type;
}
