/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:03:05 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/11 11:33:09 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria* lesson) = 0;
		virtual AMateria* createMateria(const std::string& type) = 0;
};

class MateriaSource : public IMateriaSource {
	private:
		AMateria* inventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource& operator=(const MateriaSource& rhs);
		void learnMateria(AMateria* lesson);
		AMateria* createMateria(const std::string& type);
};
