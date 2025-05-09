/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materias.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:45:00 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/16 15:24:38 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(const Ice& src);
		Ice& operator=(const Ice& rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure& src);
		Cure& operator=(const Cure& rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};
