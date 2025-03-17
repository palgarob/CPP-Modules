/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/14 12:12:50 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << ">	Create 50 grade bureaucrat" << std::endl;
	try
	{
		Bureaucrat	bureaucrat("Alfred", 50);
		std::cout << bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << ">	Create 50 grade bureaucrat, upgrade them\n>	and then downgrade themn 10 times:" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Magnolio", 50);
		bureaucrat.upGrade();
		std::cout << bureaucrat;
		for (int i = 0; i < 11; i++)
			bureaucrat.downGrade();
		std::cout << bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << ">	Try to create 154 grade bureaucrat: " << std::endl;
	try
	{
		Bureaucrat bureaucrat("Rudolph", 154);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << ">	Create a 150 grade bureaucrat and\n>	try to updgrade them: " << std::endl;
	try
	{
		Bureaucrat bureaucrat("Gurregs", 150);
		std::cout << bureaucrat;
		bureaucrat.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << ">	Create a 0 grade bureaucrat: " << std::endl;
	try
	{
		Bureaucrat bureaucrat("Godofreddy", 0);
		std::cout << bureaucrat;
		bureaucrat.downGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
