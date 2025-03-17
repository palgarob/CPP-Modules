/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 11:58:14 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	gru("gru", 1);
		Bureaucrat	minion1("minion1", 50);
		Bureaucrat	minion2("minion2", 150);
		ShrubberyCreationForm sc("target");
		PresidentialPardonForm pp("target");
		RobotomyRequestForm rr("target");
		gru.signForm(sc);
		gru.executeForm(sc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
