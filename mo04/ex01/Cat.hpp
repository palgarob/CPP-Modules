#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		Cat &	operator=(Cat const & rhs);
		~Cat();
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
