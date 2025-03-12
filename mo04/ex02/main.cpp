/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:00:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 21:00:49 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	size_t	n = 6;
	AAnimal	*animals[n];
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
	std::cout << "\nHere I make a quick copy to check that the copies are deep." << std::endl;
	Dog	pup;
	Dog	pupCpy(pup);
}
