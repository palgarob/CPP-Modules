/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:54:49 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 20:54:50 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		Animal & operator=(Animal const & rhs);
		virtual ~Animal();
		virtual void	makeSound() const;
		std::string		getType() const;
	protected:
		std::string	type;
};

#endif
