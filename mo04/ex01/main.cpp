#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	size_t	n = 6;
	Animal	*animals[n];
	std::cout << "\nCreating cats:" << std::endl;
	for (size_t i = 0; i < n / 2; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << "\nCreating dogs:" << std::endl;
	for (size_t i = n / 2; i < n; i++)
	{
		animals[i] = new Dog();
	}
	std::cout << "\nNow we make a couple make a sound: " << std::endl;
	animals[0]->makeSound();
	animals[(n / 2) + 1]->makeSound();
	std::cout << "\nNow we delete them all:" << std::endl;
	for (size_t i = 0; i < n; i++)
		delete animals[i];
	

}
