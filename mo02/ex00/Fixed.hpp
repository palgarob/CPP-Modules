class Fixed
{
	private:
		int	_value;
		static const int _nfb = 8;
	public:
		Fixed(void); // default
		Fixed(Fixed const & src); // copy
		~Fixed(void); // destructor

		Fixed &	operator=(Fixed const & rhs); // assignment

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
