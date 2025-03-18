/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:46:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/18 20:51:11 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <sstream>

void	impossible()
{
	std::cout << "char:		impossible" << std::endl;
	std::cout << "int:		impossible" << std::endl;
	std::cout << "float:	impossible" << std::endl;
	std::cout << "double:	impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.find('.', 0) != std::string::npos) {
		char* endptr;
		double num = strtod(input.c_str(), &endptr);
		if (endptr == input.c_str()) {
			impossible();
			return ;
		}
		else if (
			*endptr == 'f' && num >= std::numeric_limits<float>::min()
			&& num <= std::numeric_limits<float>::max()
		)
		{
			std::cout << "char:		" << static_cast<char>(num) << std::endl;
			std::cout << "int:		" << static_cast<int>(num) << std::endl;
			std::cout << "float:	" << num << std::endl;
			std::cout << "double:	" << static_cast<double>(num) << std::endl;
		}
		else
		{
			std::cout << "char:		" << static_cast<char>(num) << std::endl;
			std::cout << "int:		" << static_cast<int>(num) << std::endl;
			std::cout << "float:	" << static_cast<float>(num) << std::endl;
			std::cout << "double:	" << num << std::endl;
		}
	}
	else
	{
		int	num;
		std::stringstream strs(input);
		strs >> num;
		if (
			num <= std::numeric_limits<char>::max()
			&& num >= std::numeric_limits<char>::min()
		)
		{
			if (num >= 33 && num <=126)
			{
				std::cout << "char:		" << static_cast<char>(num) << std::endl;
				std::cout << "int:		" << num << std::endl;
				std::cout << "double:	" << static_cast<double>(num) << std::endl;
				std::cout << "float:	" << static_cast<float>(num) << std::endl;
			}
			else
			{
				std::cout << "char:		Non-displayable" << std::endl;
				std::cout << "int:		" << num << std::endl;
				std::cout << "double:	" << static_cast<double>(num) << std::endl;
				std::cout << "float:	" << static_cast<float>(num) << std::endl;
			}
		}
	}
}
