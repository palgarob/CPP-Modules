/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:35:55 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/12 11:35:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Memory address of the string variable:\t\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t\t" << &stringREF << std::endl;

	std::cout << "Value of the string variable:\t\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t\t\t" << stringREF << std::endl;

	return 0;
}
