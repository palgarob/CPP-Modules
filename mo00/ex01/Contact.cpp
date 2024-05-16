#include "Contact.hpp"

static std::string	get_input(std::string prompt)
{
	std::string	answer;

	do {
		std::cout << prompt << std::flush;
		std::cin >> answer;
		if (!std::cin.good() || answer.empty())
		{
			std::cin.clear();
			std::cout << "Invalid, try again" << std::endl;
		}
		else
			break;
	} while (1);
}

Contact::Contact() {}

Contact::~Contact() {}

//Comprobar si es necesario poner la definición del constructor

void	Contact::init(void)
{
	std::cout << "init" << std::endl;
	/* this->_first_name = get_input("first name: ");
	this->_last_name = get_input("last name: ");
	this->_nickname = get_input("nickname: ");
	this->_number = get_input("phone number: ");
	this->_secret = get_input("darkest secret: "); */
}
