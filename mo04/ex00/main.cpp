#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

/* When calling delete, we need to make sure that the destructors of the parent class
have the virtual keyword, so that the deestructors of the child classes are correctly
called. There are comments on the code of this exercise to prove that otherwise it
could lead to memory leaks */

int	main(void)
{
	std::cout << "\n*-*-*-*-*-*-*-*-*-*- 1. ON THE STACK -*-*-*-*-*-*-*-*" << std::endl;
	{
		std::cout << "\n->First let's create a Dog and a Cat:" << std::endl;
		Dog	dog;
		Cat	cat;
		std::cout << "\n->And we will create two Animal * (pointers) that point to each cat and dog" << std::endl;
		Animal	*AnimalPtr1 = &dog;
		Animal	*AnimalPtr2 = &cat;
		std::cout << "Ptr1 has type: " << AnimalPtr1->getType() << std::endl;
		std::cout << "Ptr2 has type: " << AnimalPtr2->getType() << std::endl;
		std::cout << "\n->Now let's check that they make the sound that they should:" << std::endl;
		std::cout << "using Ptr1 we get the sound: " << std::flush;
		AnimalPtr1->makeSound();
		std::cout << "using Ptr2 we get the sound: " << std::flush;
		AnimalPtr2->makeSound();
		std::cout << "\n->Now let's create a generic animal" << std::endl;
		Animal	animal;
		std::cout << "which makes the sound: " << std::flush;
		animal.makeSound();
		std::cout << "\n->Now let's create a WrongCat: " << std::endl;
		WrongCat	wrongCat;
		std::cout << "\n->And we will create a WrongAnimal * (pointer) that points to the cat" << std::endl;
		WrongAnimal	*WrongAnimalPtr = &wrongCat;
		std::cout << "Ptr has type: " << WrongAnimalPtr->getType() << std::endl;
		std::cout << "\n->Now we'll see that despite it having the type 'cat', it makes the generic sound:" << std::endl;
		std::cout << "using the Ptr we get the sound: " << std::flush;
		WrongAnimalPtr->makeSound();
		std::cout << "\n->Since now we are going out of scope, the destructors will be called:" << std::endl;
	}
	std::cout << "\n*-*-*-*-*-*-*-*-*-*- 2. ON THE HEAP -*-*-*-*-*-*-*-*" << std::endl;
	{
		std::cout << "\n->Let's create an Animal * (pointer) that'll point to a cat located on heap:" << std::endl;
		Animal	*catptr = new Cat;
		std::cout << "\n->It has type: " << catptr->getType() << std::endl;
		std::cout << "And it makes the sound: " << std::flush; 
		catptr->makeSound();
		std::cout << "\n->Now, since we don't need that cat anymore, we will delete it:" << std::endl;
		delete catptr;
		std::cout << "\n->Let's do the same but with WrongCat:" << std::endl;
		WrongAnimal	*wcatptr = new WrongCat;
		std::cout << "\n->It has type: " << wcatptr->getType() << std::endl;
		std::cout << "And it makes the sound: " << std::flush; 
		wcatptr->makeSound();
		std::cout << "\n->And delete it:" << std::endl;
		delete wcatptr;
	}
}
