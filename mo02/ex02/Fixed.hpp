/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:18:43 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 19:53:22 by pepaloma         ###   ########.fr       */
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
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed &	operator=(Fixed const & rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		/// COMPARISON OPERATORS
		bool	operator<(Fixed const & rhs) const;
		bool	operator>(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		/// ARITHMETIC OPERATORS
		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;

		/// INCREMENT & DECREMENT OPERATORS
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);

		/// MIN & MAX
		static Fixed &			min(Fixed & a, Fixed & b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed &			max(Fixed & a, Fixed & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
