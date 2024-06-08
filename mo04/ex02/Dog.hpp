#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const & src);
		Dog &	operator=(Dog const & rhs);
		~Dog();
		void	makeSound();
	private:
		Brain	*brain;
};

#endif
