/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:00 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/03 17:43:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "PmergeMe.hpp"
#include <limits>

static long g_list_time = 0;
static long g_vector_time = 0;

void parse_list(const std::vector<std::string> args, PmergeMe::List& v)
{
	std::stringstream ss;
	long long n;
	for (std::size_t i = 0; i < args.size(); i++)
	{
		ss.clear(); ss.str(args[i]); ss >> n;
		if (ss.fail() || !(ss.eof()))
		{
			std::cerr << "Error: Wrong input format\n" << args[i] << std::endl;
			exit(1);
		}
		if (
			n > std::numeric_limits<unsigned>::max()
			|| n < std::numeric_limits<unsigned>::min()
		)
		{
			std::cerr << "Error: range should be inside unsigned int " << args[i] << std::endl;
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
		if (ss.fail())
		{
			std::cerr << "Error: Wrong input format\n" << args[i] << std::endl;
			exit(1);
		}
		v.push_back(n);
	}
}

PmergeMe::Vector with_vector(std::vector<std::string> args)
{
	std::clock_t start = std::clock();
	PmergeMe::Vector result;
	parse_vector(args, result);

	result.mergeInsertSort();
	/* for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	} */
	std::clock_t end = std::clock();
	g_vector_time = static_cast<long>((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6);
	return (result);
}

PmergeMe::List with_list(std::vector<std::string> args)
{
	std::clock_t start = std::clock();
	PmergeMe::List result;
	parse_list(args, result);

	result.mergeInsertSort();
	/* for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	} */
	std::clock_t end = std::clock();
	g_list_time = static_cast<long>((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: wrong number of arguments";
		return(1);
	}
	std::vector<std::string> args;
	for (int i = 1; i < argc; i++)
	{
		args.push_back(argv[i]);
	}
	PmergeMe::List l_sorted = with_list(args);
	PmergeMe::Vector v_unsorted; parse_vector(args, v_unsorted);
	PmergeMe::List l_unsorted; parse_list(args, l_unsorted);
	PmergeMe::Vector v_sorted = with_vector(args);
 	std::cout << "Before:	"; PmergeMe::printNumbers(v_unsorted); std::cout << std::endl;
//	std::cout << "Before:	"; PmergeMe::printNumbers(l_unsorted); std::cout << std::endl;
//	std::cout << "After:	"; PmergeMe::printNumbers(v_sorted); std::cout << std::endl;
	std::cout << "After:	"; PmergeMe::printNumbers(l_sorted); std::cout << std::endl;
	std::cout << "Time to process a range of " << v_sorted.size() << " elements with a vector: " << g_vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << l_sorted.size() << " elements with a list: " << g_list_time << " us" << std::endl;
}
