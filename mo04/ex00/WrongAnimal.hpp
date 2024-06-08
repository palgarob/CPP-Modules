#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal & operator=(WrongAnimal const & rhs);
		virtual ~WrongAnimal(); //virtual is necessary so that the destructors are called correctly
		void			makeSound();
		std::string		getType();
	protected:
		std::string			type;
};

#endif
