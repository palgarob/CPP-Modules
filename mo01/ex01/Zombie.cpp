#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << this->_name << " says bye!" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
