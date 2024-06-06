#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	{
	ScavTrap	Josephine("Josephine");
	Josephine.attack("enemy");
	Josephine.beRepaired(600);
	Josephine.takeDamage(197);
	Josephine.guardGate();
	ClapTrap	Immanuel("Immanuel");
	}
	{
		FragTrap	Edward("Edward");
		Edward.highFivesGuys();
		Edward.attack("someone");
	}
	return 0;
}
