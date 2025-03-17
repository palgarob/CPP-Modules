/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:00:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 17:06:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		{Bureaucrat b;
		std::cout << b << std::endl;
		Form f("default form", 50, 10);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << "______________________" << std::endl;
		Form f2("default form 2", -5, 30);}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
