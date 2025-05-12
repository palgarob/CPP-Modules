/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:06:58 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/11 11:22:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {}
AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia aimed at " << target.getName() << std::endl;
}

Ice::Ice() : AMateria("ice") {}
Ice::~Ice() {}
AMateria* Ice::clone() const {
	return new Ice;
}
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
AMateria* Cure::clone() const {
	return new Cure;
}
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
