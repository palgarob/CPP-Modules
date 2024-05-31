class Fixed
{
	private:
		int	value;
		static const int nfb = 8;
	public:
		Fixed(void);
		~Fixed(void);
};

Fixed::Fixed() : value(0)
{
}

Fixed::~Fixed()
{
}

