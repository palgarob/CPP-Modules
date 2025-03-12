/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:35:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 11:35:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie*	horde = new Zombie[N];

	for (int i=0; i < N; i++)
	{
		std::string	nameN = name;
		nameN += (i + '0');
		horde[i].setName(nameN);
	}

	return horde;
}
