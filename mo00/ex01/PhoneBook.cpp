#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : next_entry(0), n_contacts(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void)
{
	std::cout << "\nEnter contact information:" << std::endl;
	this->_contacts[this->next_entry].init();
	this->next_entry == 7 ? this->next_entry = 0 : this->next_entry++;
	if (this->n_contacts < 8) this->n_contacts++;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search(void)
{
	if (this->n_contacts == 0)
		std::cout << "\nYou don't have contacts yet" << std::endl;
	else
	{
		int	index;
		if (n_contacts == 1)
		{
			std::cout << "\nYou only have one contact" << std::endl;
			index = 0;
		}
		else
		{
			std::cout << "\nThese are your contacts:" << std::endl;
			std::cout << std::setw(10) << "index" << "|";
			std::cout << std::setw(10) << "first name" << "|";
			std::cout << std::setw(10) << "last name" << "|";
			std::cout << std::setw(10) << "nickname" << std::endl;
			for (int i = 0; i < this->n_contacts ; i++)
			{
				std::cout << std::setw(10) << i << "|" << std::flush;
				this->_contacts[i].display();
			}
			do {
				std::cout << "Enter an index number: " << std::flush;
				std::cin >> index;
				if (!std::cin.good() || index < 0 || index > this->n_contacts) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid, try again" << std::endl;
				}
				else {std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); break;}
			} while (1);
		}
		this->_contacts[index].show();
	}
}
