/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 16:41:27 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		{Bureaucrat b;
		std::cout << b << std::endl;}

		/*
		{Bureaucrat b("bureaucrat", 73);
		std::cout << b << std::endl;}

		{Bureaucrat b("bureaucrat", 0);
		std::cout << b << std::endl;}
		
		{Bureaucrat b("bureaucrat", -4);
		std::cout << b << std::endl;}

		{Bureaucrat b("bureaucrat", 170937);
		b.upGrade();
		std::cout << b << std::endl;}

		{Bureaucrat b("bureaucrat", 1);
		b.upGrade();
		std::cout << b << std::endl;}

		{Bureaucrat b("bureaucrat", 150);
		b.downGrade();
		std::cout << b << std::endl;}
		*/
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
