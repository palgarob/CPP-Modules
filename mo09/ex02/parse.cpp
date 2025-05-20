/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:15:26 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 12:47:17 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <sstream>
#include <cstddef>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <list>
#include <cstdio>

#include "PmergeMe.hpp"

void parse_list(const std::vector<std::string> args, PmergeMe::List& v)
{
	std::stringstream ss;
	long long n;
	for (std::size_t i = 0; i < args.size(); i++)
	{
		ss.clear(); ss.str(args[i]); ss >> n;
		if (ss.fail() || (ss.peek() != EOF))
		{
			std::cerr << "Error: Wrong input format. Problem: " << args[i] << std::endl;
			exit(1);
		}
		if (
			n > std::numeric_limits<unsigned>::max()
			|| n < std::numeric_limits<unsigned>::min()
		)
		{
			std::cerr << "Error: range should be inside unsigned int. Problem: " << args[i] << std::endl;
			exit(1);
		}
		v.push_back(n);
	}
}

void parse_vector(const std::vector<std::string> args, PmergeMe::Vector& v)
{
	std::stringstream ss;
	long long n;
	for (std::size_t i = 0; i < args.size(); i++)
	{
		ss.clear(); ss.str(args[i]); ss >> n;
		if (ss.fail() || ss.peek() != EOF)
		{
			std::cerr << "Error: Wrong input format. Problem: " << args[i] << std::endl;
			exit(1);
		}
		if (
			n > std::numeric_limits<unsigned>::max()
			|| n < std::numeric_limits<unsigned>::min()
		)
		{
			std::cerr << "Error: range should be inside unsigned int. Problem: " << args[i] << std::endl;
			exit(1);
		}
		v.push_back(n);
	}
}
