#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "***Welcome to The Battle of the ClapTraps!!!***\n\n" << std::endl;
	std::cout << "First round: Charlie vs. Marley" << std::endl;
	ClapTrap	Charlie("Charlie");
	ClapTrap	Marley("Marley");
	Charlie.attack("Marley");
	Marley.attack("Charlie");
	std::cout << "\nBut nothing happens because their damage is 0!!" << std::endl;
	std::cout << "Otherwise it would've looked like this:" << std::endl;
	Marley.takeDamage(3);
	std::cout << "\nAlso, remember they can heal themselves as well" << std::endl;
	Marley.beRepaired(3);
	std::cout << "\nNow that the round is finished, they will both be destroyed" << std::endl;
	return 0;
}
