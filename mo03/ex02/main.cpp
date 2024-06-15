#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "***Welcome to The Battle of the ClapTraps!!!***\n" << std::endl;
	std::cout << "First round: Charlie vs. Shearly" << std::endl;
	ClapTrap	Charlie("Charlie");
	FragTrap	Shearly("Shearly");
	std::cout << "\nLet the battle begin" << std::endl;
	Charlie.attack("Shearly");
	std::cout << "But nothing happens because its damage is 0!!" << std::endl;
	Shearly.attack("Charlie");
	Charlie.takeDamage(30);
	std::cout << "\nAlso, remember they can heal themselves as well" << std::endl;
	Charlie.beRepaired(5);
	std::cout << "And FragTraps can highfive the team" << std::endl;
	Shearly.highFivesGuys();
	std::cout << "\nNow that the round is finished, they will both be destroyed" << std::endl;
}
