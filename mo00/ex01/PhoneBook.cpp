#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void)
{
	std::cout << "add" << std::endl;
	this->_contacts[0].init();
	return ;
}

void	PhoneBook::search(void)
{
	std::cout << "search" << std::endl;
	return ;
}
