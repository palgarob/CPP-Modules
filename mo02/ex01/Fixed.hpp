#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _nfb = 8;
	public:
		Fixed(void); // default
		Fixed(Fixed const & src); // copy
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void); // destructor

		Fixed &	operator=(Fixed const & rhs); // assignment

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

//100110100100110111100000000
//000000000000000010011010010
