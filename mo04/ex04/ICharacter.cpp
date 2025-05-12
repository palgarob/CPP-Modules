/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:58:49 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/11 12:24:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::~ICharacter() {}

Character::Character() {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const std::string& name) : _name(name) {
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::~Character() {
	if (this->inventory[0]) delete this->inventory[0];
	if (this->inventory[1]) delete this->inventory[1];
	if (this->inventory[2]) delete this->inventory[2];
	if (this->inventory[3]) delete this->inventory[3];
}

Character::Character(const Character& src)
{
	*this = src;
}

Character& Character::operator=(const Character& rhs)
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

const std::string& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (this->inventory[i] && i < 4) i++;
	if (i == 4)
		std::cerr << "Error: This materia source can't take more the 4 materias" << std::endl;
	else
		this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
