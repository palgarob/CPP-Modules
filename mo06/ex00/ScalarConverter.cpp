/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:46:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/21 15:20:25 by pepaloma         ###   ########.fr       */
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
	std::cout << "float:		impossible" << std::endl;
	std::cout << "double:		impossible" << std::endl;
}

void	output(int integer, float floating, double doublePrecision)
{
	if (integer < 33 || integer > 126)
		std::cout << "char:		Non displayable" << std::endl;
	else if (
		integer > std::numeric_limits<char>::max()
		|| integer < std::numeric_limits<char>::min()
	)
		std::cout << "char:		impossible" << std::endl;
	else
		std::cout << "char:		" << static_cast<char>(integer) << std::endl;
	std::cout << "int:		" << integer << std::endl;
	std::cout << "float:		" << floating 
	<< (std::abs(floating - static_cast<int>(floating)) > 0 ? "" : ".0") << "f" << std::endl;
	std::cout << "double:		" << doublePrecision
	<< (std::abs(floating - static_cast<int>(floating)) > 0 ? "" : ".0") << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	char* endptr;
	double num = strtod(input.c_str(), &endptr);
	if (endptr == input.c_str()) {
		impossible();
	}
	else if (input.find('.', 0) != std::string::npos) {
		if (
			*endptr == 'f' && num >= std::numeric_limits<float>::min()
			&& num <= std::numeric_limits<float>::max()
		)
		{
			output(
				static_cast<int>(num),
				num, static_cast<double>(num)
			);
		}
		else
		{
			output(
				static_cast<int>(num),
				static_cast<float>(num), num
			);
		}
	}
	else if (
		!input.compare(0, 4, "-inf") || !input.compare(0, 4, "+inf")
		|| !input.compare(0, 3, "nan")
	)
	{
		std::cout << "char:		impossible" << std::endl;
		std::cout << "int:		impossible" << std::endl;
		std::cout << "float:	"
		<< ('f' == (char)input.at(4) ? input.substr(0, 4) : input.substr(0, 3)) << "f" << std::endl;
		std::cout << "double:	"
		<< ((input.at(2) == 'i') ? input.substr(0, 4) : input.substr(0, 3)) << std::endl;
	}
	else if (
		!input.compare(0, 5, "-inff") || !input.compare(0, 5, "+inff")
		|| !input.compare(0, 4, "nanf")
	)
	{
		std::cout << "char:		impossible" << std::endl;
		std::cout << "int:		impossible" << std::endl;
		std::cout << "float:	"
		<< ((input.at(2) == 'i') ? input.substr(0, 5) : input.substr(0, 4)) << std::endl;
		std::cout << "double:	"
		<< ((input.at(2) == 'i') ? input.substr(0, 4) : input.substr(0, 3)) << std::endl;
	}
	else
	{
		long long	num;
		std::stringstream strs(input);
		strs >> num;
		if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
			impossible();
		else
		{
			output(
				static_cast<int>(num),
				static_cast<float>(num),
				static_cast<double>(num)
			);
		}
	}
}
