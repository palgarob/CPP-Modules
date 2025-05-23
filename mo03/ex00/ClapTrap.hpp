#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_health;
	unsigned int	_energy;
	unsigned int	_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	ClapTrap &	operator=(ClapTrap const & rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};


#endif
