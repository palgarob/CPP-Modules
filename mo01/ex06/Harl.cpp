/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:57:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 17:57:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() const {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my burger.\n\n";
}

void Harl::info() const {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n\n";
}

void Harl::warning() const {
	std::cout << "[ WARNING ]\nI think I deserve some extra bacon for free.\n\n";
}

void Harl::error() const {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(char *str) const {
	void (Harl::*func_ptr[4])() const = {&Harl::debug, &Harl::info, &Harl::warning,
								   &Harl::error};
	std::string level(str);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i <= 3; i++) {
		if (i == 3 && level != levels[i]) {
			i = -1;
			break;
		}
		if (level == levels[i])
			break;
	}

	switch (i) {
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		case 0:
			(this->*func_ptr[0])();
			// fallthrough
		case 1:
			(this->*func_ptr[1])();
			// fallthrough
		case 2:
			(this->*func_ptr[2])();
			// fallthrough
		case 3:
			(this->*func_ptr[3])();
			break;

	}
}
