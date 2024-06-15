#include "PhoneBook.hpp"
#include <limits>
#include <cstdio>

int	main(void)
{
	PhoneBook	my_phonebook;
	std::string	command;

	do
	{
		std::cout << "\nEnter a valid command (ADD, SEARCH or EXIT)\n-> " << std::flush;
		std::getline(std::cin, command);
		if (!std::cin.good())
		{
			if (std::cin.eof())
			{
				std::cout << "EOF read, input stream fu**ed up." << std::endl;
				return 1;
			}
			std::cin.clear();
			continue;
		}
		if (!command.compare("ADD"))
			my_phonebook.add();
		else if (!command.compare("SEARCH"))
			my_phonebook.search();
		else if (!command.compare("EXIT"))
			break;
		else
			std::cout << "\nNot a valid command, try again" << std::endl;
	} while (1);
}
