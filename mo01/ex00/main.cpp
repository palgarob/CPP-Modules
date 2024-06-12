#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\nI create a zombie ('stacky') in stack and make it announce itself" << std::endl;
	Zombie	stack_zombo("stacky");
	stack_zombo.announce();

	std::cout << "\nI create a zombie ('heapy') in heap and make it announce itself" << std::endl;
	Zombie	*heap_zombo = new Zombie("heapy");
	heap_zombo->announce();

	std::cout << "\nI use the newZombie function to create a zombie ('dinamy') in heap but it doesn't announce itself" << std::endl;
	Zombie	*heap_zombo2 = newZombie("dinamy");

	std::cout << "\nI delete heapy and dinamy, since I don't need them anymore" << std::endl;
	delete heap_zombo;
	delete heap_zombo2;

	std::cout << "\nI use the randomChump function to create a zombie ('scopy'). As soon as the zombie goes out of scope, the destructor is called" << std::endl;
	randomChump("scopy");

	std::cout << "\nNow the program will finish, so stacky's destructor will be called automatically" << std::endl;
}
