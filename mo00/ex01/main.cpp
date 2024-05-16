#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	my_phonebook;
	std::string	command;

	do
	{
		std::cin >> command;
		if (command.compare("ADD"))
			my_phonebook.add();
		if (command.compare("SEARCH"))
			my_phonebook.search();
	} while (!command.compare("EXIT"));

	return 0;
}
