/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:19:45 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/05 12:09:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <sstream>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: number of arguments" << std::endl;
		exit(1);
	}
	RPN Calculator;
	std::stringstream ss;
	std::string s;
	ss.str(argv[1]);
	try {
		while (std::getline(ss, s, ' '))
		{
			if (s.length() != 1)
				throw (RPN::InputError());
			try {
				Calculator.newInput(s[0]);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				exit(1);
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit (1);
	}
	try {
		Calculator.result();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}
