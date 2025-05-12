/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:41:59 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/11 12:07:57 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;
class AMateria
{
	private:
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& rhs);
		AMateria();
	protected:
		std::string _type;
	public:
		virtual ~AMateria();
		AMateria(const std::string& type);
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class Ice : public AMateria {
	private:
		Ice(const Ice& src);
		Ice& operator=(const Ice& rhs);
	public:
		Ice();
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

class Cure : public AMateria {
	private:
		Cure(const Cure& src);
		Cure& operator=(const Cure& rhs);
	public:
		Cure();
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
