#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const & src);
		AAnimal & operator=(AAnimal const & rhs);
		virtual ~AAnimal();
		virtual void	makeSound() const = 0;
		std::string		getType() const;
	protected:
		std::string	type;
};

#endif
