/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:06:07 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/12 09:50:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource() {}

MateriaSource::MateriaSource() {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}
MateriaSource::~MateriaSource() {
	if (this->inventory[0]) delete this->inventory[0];
	if (this->inventory[1]) delete this->inventory[1];
	if (this->inventory[2]) delete this->inventory[2];
	if (this->inventory[3]) delete this->inventory[3];
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		if (rhs.inventory[0])
		this->inventory[0] = rhs.inventory[0]->clone();
		if (rhs.inventory[1])
		this->inventory[1] = rhs.inventory[1]->clone();
		if (rhs.inventory[2])
		this->inventory[2] = rhs.inventory[2]->clone();
		if (rhs.inventory[3])
		this->inventory[3] = rhs.inventory[3]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* lesson)
{
	int i = 0;
	while (i < 4 && this->inventory[i])
		i++;
	if (i == 4)
		std::cerr << "Error: This materia source can't take more than 4 materias" << std::endl;
	else
		this->inventory[i] = lesson;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	int i = 0;
	while (i < 4 && this->inventory[i] && this->inventory[i]->getType() != type)
		i++;
	if (i == 4 || !this->inventory[i])
	{
		std::cerr << "Error: materia not inside materia source" << std::endl;
		return NULL;
	}
	return this->inventory[i]->clone();
}
