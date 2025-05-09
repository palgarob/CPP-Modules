/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:06:58 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/16 15:22:42 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const AMateria& src) {
	*this = src;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	(void)rhs;
	return *this;
}

AMateria::AMateria(const std::string& type) : _type(type) {}

const std::string& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia aimed at " << target.getName() << std::endl;
}
