/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:00:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 21:00:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat const & src);
		Cat &	operator=(Cat const & rhs);
		~Cat();
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
