/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:00 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 16:20:30 by pepaloma         ###   ########.fr       */
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

bool checkArguments(int argc)
{
	if (argc < 2)
	{
		std::cerr << "Error: wrong number of arguments";
		return false;
	}
	return true;
}

std::vector<std::string> getArgumentsVector(int argc, char **argv)
{
	std::vector<std::string> args;
	for (int i = 1; i < argc; i++)
	{
		args.push_back(argv[i]);
	}
	return args;
}

int main(int argc, char **argv)
{
	if (!checkArguments(argc))
		return 1;

	std::vector<std::string> args = getArgumentsVector(argc, argv);
	PmergeMe::Vector v_unsorted; parse_vector(args, v_unsorted);
	PmergeMe::List l_unsorted; parse_list(args, l_unsorted);
	PmergeMe::List l_sorted;
	double list_time = benchmark_list(args, l_sorted);
	PmergeMe::Vector v_sorted;
	double vector_time = benchmark_vector(args, v_sorted);
	std::cout << "Before:	"; PmergeMe::printNumbers(v_unsorted); std::cout << std::endl;
	std::cout << "Before:	"; PmergeMe::printNumbers(l_unsorted); std::cout << std::endl;
	std::cout << "After:	"; PmergeMe::printNumbers(v_sorted); std::cout << std::endl;
	std::cout << "After:	"; PmergeMe::printNumbers(l_sorted); std::cout << std::endl;
	std::cout << "Time to process a range of " << v_sorted.size() << " elements with a vector: " << vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << l_sorted.size() << " elements with a list: " << list_time << " us" << std::endl;
}
