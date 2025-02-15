#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed &	operator=(Fixed const & rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
