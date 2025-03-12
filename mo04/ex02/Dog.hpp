/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:00:44 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 21:00:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & src);
		Dog &	operator=(Dog const & rhs);
		~Dog();
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
