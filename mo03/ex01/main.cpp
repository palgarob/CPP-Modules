#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	Josephine("Josephine");
	ScavTrap	Jo(Josephine);
	Josephine.attack("enemy");
	Josephine.beRepaired(600);
	Josephine.takeDamage(197);
	Josephine.guardGate();
	ClapTrap	Immanuel("Immanuel");
	return 0;
}
