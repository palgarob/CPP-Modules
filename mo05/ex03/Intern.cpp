/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:07:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 12:37:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern&src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	if (!name.compare("SCF"))
		return (new ShrubberyCreationForm(target));
	if (!name.compare("PPF"))
		return (new PresidentialPardonForm(target));
	if (!name.compare("RRF"))
		return (new RobotomyRequestForm(target));
	throw(Intern::FormDoesntExistException());
}

const char* Intern::FormDoesntExistException::what() const throw() {
	return ("Intern::FormDoesntExistException: The name provided to create the form doesn't exist: SCF PPF or RRF");
}
