#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void)
{
	static int i = 0;
	this->_contacts[i % 8].init();
	i++;
}
