#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	public:
		Fixed(void); // default
		Fixed(Fixed const & src); // copy
		~Fixed(void); // destructor

		Fixed &	operator=(Fixed const & rhs); // assignment

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
