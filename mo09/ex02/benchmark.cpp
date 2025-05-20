/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:22:02 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 12:32:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include "PmergeMe.hpp"

double benchmark_vector(std::vector<std::string> args, PmergeMe::Vector& result)
{
	std::clock_t start = std::clock();
	parse_vector(args, result);
	if (result.size() > 1)
		result.mergeInsertSort();
	std::clock_t end = std::clock();
	double time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
	return (time);
}

double benchmark_list(std::vector<std::string> args, PmergeMe::List& result)
{
	std::clock_t start = std::clock();
	parse_list(args, result);
	if (result.size() > 1)
		result.mergeInsertSort();
	std::clock_t end = std::clock();
	double time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
	return (time);
}
