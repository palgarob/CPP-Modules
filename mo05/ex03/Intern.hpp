/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:02:31 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 20:26:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& rhs);

	AForm* makeForm(const std::string& name, const std::string& target) const;
	class FormDoesntExistException : public std::exception {
		const char* what() const throw();
	};
};

#endif
