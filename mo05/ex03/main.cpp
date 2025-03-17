/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 20:52:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Intern i;
		Bureaucrat b("b", 1);
		AForm* f = i.makeForm("SCF", "HOLA");
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
