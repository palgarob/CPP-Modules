/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:53:09 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/11 18:53:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _next_entry(0), _n_contacts(0) {}

void	PhoneBook::add(void)
{
	std::cout << "\nEnter contact information:" << std::endl;
	this->_contacts[this->_next_entry].init();
	this->_next_entry == 7 ? this->_next_entry = 0 : this->_next_entry++;
	if (this->_n_contacts < 8) this->_n_contacts++;
	return ;
}

void	PhoneBook::search(void)
{
	if (this->_n_contacts == 0)
		std::cout << "\nYou don't have contacts yet" << std::endl;
	else
	{
		int	index;
		if (_n_contacts == 1)
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
			for (int i = 0; i < this->_n_contacts ; i++)
			{
				std::cout << std::setw(10) << i << "|" << std::flush;
				this->_contacts[i].display();
			}
			do {
				std::cout << "Enter an index number: " << std::flush;
				std::cin >> index;
				if (!std::cin.good() || index < 0 || index > this->_n_contacts) {
					if (std::cin.eof())
					{
						std::cout << "EOF read, input stream fu**ed up." << std::endl;
						exit(1);
					}
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
