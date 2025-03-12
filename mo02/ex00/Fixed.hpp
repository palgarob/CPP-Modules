/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:18:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/11 10:20:11 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	public:
		Fixed();
		~Fixed(void);
		Fixed(Fixed const & src);
		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
