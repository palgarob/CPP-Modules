#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {

	Zombie*	horde = new Zombie[N];

	for (int i=0; i < N; i++)
	{
		std::string	num = name;
		num += (i + '0');
		horde[i].setName(num);
	}

	return horde;
}
