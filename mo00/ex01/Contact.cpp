#include "Contact.hpp"

static std::string	get_input(std::string prompt)
{
	std::string	answer;

	do {
		std::cout << prompt << std::flush;
		std::getline(std::cin, answer);
		if (!std::cin.good() || answer.empty())
		{
			std::cin.clear();
			std::cout << "Invalid, try again" << std::endl;
		}
		else
			break;
	} while (1);
	return answer;
}

static std::string	trunc(std::string s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void	Contact::init(void)
{
	this->_first_name = get_input("first name: ");
	this->_last_name = get_input("last name: ");
	this->_nickname = get_input("nickname: ");
	this->_number = get_input("phone number: ");
	this->_secret = get_input("darkest secret: ");
}

void	Contact::display(void) const
{
	std::cout << std::setw(10) << trunc(this->_first_name) << "|";
	std::cout << std::setw(10) << trunc(this->_last_name) << "|";
	std::cout << std::setw(10) << trunc(this->_nickname) << std::endl;
}

void	Contact::show(void) const
{
	std::cout << "first name: " << this->_first_name << std::endl;
	std::cout << "last name: " << this->_last_name << std::endl;
	std::cout << "nickname: " << this->_nickname << std::endl;
	std::cout << "number: " << this->_number << std::endl;
	std::cout << "darkest secret: " << this->_secret << std::endl;
}

