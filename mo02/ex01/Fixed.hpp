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
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(Fixed const & src);
		Fixed &	operator=(Fixed const & rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
