/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:18:40 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/11 10:20:47 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);
		Fixed &	operator=(Fixed const & rhs);

		Fixed(const int integer);
		Fixed(const float floating);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
