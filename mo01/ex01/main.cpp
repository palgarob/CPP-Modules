/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:35:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 11:35:29 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\nI create a horde of 5 zombies and name them 'zombo'" << std::endl;
	Zombie* horde = zombieHorde(5, "zombo");

	std::cout << "\nI make all announce themselves" << std::endl;
	for (int i=0; i < 5; i++)
		horde[i].announce();

	std::cout << "\nI delete them" << std::endl;
	delete [] horde;

	std::cout << "\nI create a horde of 9 zombies and name them 'walker'" << std::endl;
	Zombie*	horde2 = zombieHorde(9, "walker");

	std::cout << "\nI make a couple announce themselves" << std::endl;
	horde2[1].announce();
	horde2[8].announce();

	std::cout << "\nI delete them all" << std::endl;
	delete [] horde2;

	return 0;
}
