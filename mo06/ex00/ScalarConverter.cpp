/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:46:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/31 08:37:26 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>

static void printInt(int i)
{
	if (i >= 33 && i <= 126)
		std::cout << "char:		" << static_cast<char>(i) << std::endl;
	else if (
		i >= std::numeric_limits<char>::min()
		&& i <= std::numeric_limits<char>::max()
	)
		std::cout << "char:		Non displayable" << std::endl;
	else
		std::cout << "char:		impossible" << std::endl;
	std::cout << "int:		" << i << std::endl;
	std::cout << "float:		" << static_cast<float>(i) << ".0" << "f" << std::endl;
	std::cout << "double:		" << static_cast<double>(i) << ".0" << std::endl;
}

static void printFloat(float i)
{
	if (i >= 33 && i <= 126)
		std::cout << "char:		" << static_cast<char>(i) << std::endl;
	else if (
		i >= std::numeric_limits<char>::min()
		&& i <= std::numeric_limits<char>::max()
	)
		std::cout << "char:		Non displayable" << std::endl;
	else
		std::cout << "char:		impossible" << std::endl;
	std::cout << "int:		" << static_cast<int>(i) << std::endl;
	std::cout << "float:		" << i << (std::fmod(i, 1.0) == 0 ? ".0" : "") << "f" << std::endl;
	std::cout << "double:		" << static_cast<double>(i) << (std::fmod(i, 1.0) == 0 ? ".0" : "") << std::endl;
}

static void printDouble2(double i)
{
	if (i >= 33 && i <= 126)
		std::cout << "char:		" << static_cast<char>(i) << std::endl;
	else if (
		i >= std::numeric_limits<unsigned char>::min()
		&& i <= std::numeric_limits<unsigned char>::max()
	)
		std::cout << "char:		Non displayable" << std::endl;
	else
		std::cout << "char:		impossible" << std::endl;
	std::cout << "int:		" << static_cast<int>(i) << std::endl;
	std::cout << "float:		" << static_cast<float>(i) << (std::fmod(i, 1.0) == 0 ? ".0" : "") << "f" << std::endl;
	std::cout << "double:		" << i << (std::fmod(i, 1.0) == 0 ? ".0" : "") << std::endl;
}

static void printDouble1(double i)
{
	std::cout << "char:		impossible" << std::endl;
	std::cout << "int:		impossible" << std::endl;
		std::cout << "float:		" << static_cast<float>(i) << (std::fmod(i, 1.0) == 0 ? ".0" : "") << "f" << std::endl;
	std::cout << "double:		" << i << (std::fmod(i, 1.0) == 0 ? ".0" : "") << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	char* endptr;
	errno = 0;
	double dou = strtod(input.c_str(), &endptr);
	if (errno == ERANGE || endptr == input.c_str()) {
		std::cout << "char:		impossible" << std::endl;
		std::cout << "int:		impossible" << std::endl;
		std::cout << "float:		impossible" << std::endl;
		std::cout << "double:		impossible" << std::endl;
	}
	else if (input.find('.', 0) == std::string::npos)
	{
		if (
			dou <= std::numeric_limits<int>::max()
			&& dou >= std::numeric_limits<int>::min()
		) {
			int i = std::strtol(input.c_str(), &endptr, 10);
			printInt(i);
		}
		else {
			printDouble1(dou);
		}
	}
	else {
		errno = 0;
		float flo = strtof(input.c_str(), &endptr);
		if (*endptr == 'f' && errno == 0) {
			printFloat(flo);
		}
		else {
			printDouble2(dou);
		}
	}
}
