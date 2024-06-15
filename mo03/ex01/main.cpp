#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "***Welcome to The Battle of the ClapTraps!!!***\n" << std::endl;
	std::cout << "First round: Charlie vs. Harley" << std::endl;
	ClapTrap	Charlie("Charlie");
	ScavTrap	Harley("Harley");
	std::cout << "\nLet the battle begin" << std::endl;
	Charlie.attack("Harley");
	std::cout << "But nothing happens because its damage is 0!!" << std::endl;
	Harley.attack("Charlie");
	Charlie.takeDamage(20);
	std::cout << "\nAlso, remember they can heal themselves as well" << std::endl;
	Charlie.beRepaired(5);
	std::cout << "And ScavTraps can enter guard mode" << std::endl;
	Harley.guardGate();
	std::cout << "\nNow that the round is finished, they will both be destroyed" << std::endl;
}
