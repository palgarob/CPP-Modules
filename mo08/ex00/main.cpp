/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:50:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:51 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
int main()
{
	/* std::vector<int> vec;
	vec.push_back(34);  // 1
	vec.push_back(31);  // 2
	vec.push_back(65);  // 3
	vec.push_back(-23); // 4
	vec.push_back(47);  // 5
	vec.push_back(89);  // 6
	vec.push_back(-56); // 7
	vec.push_back(12);  // 8
	vec.push_back(78);  // 9
	vec.push_back(-99); // 10
	vec.push_back(0);   // 11
	vec.push_back(45);  // 12
	vec.push_back(-67); // 13
	vec.push_back(33);  // 14
	vec.push_back(19);  // 15
	vec.push_back(88);  // 16
	vec.push_back(-42); // 17
	vec.push_back(73);  // 18
	try {
		int pos = easyfind(vec, -56) + 1;
		std::cout << "Found at position: " << pos << std::endl;
	} catch (const std::exception& e)
	{
		std::cerr << "Not found" << std::endl;
	} */
	std::list<int> vec;
	vec.push_back(34);  // 1
	vec.push_back(31);  // 2
	vec.push_back(65);  // 3
	vec.push_back(-23); // 4
	vec.push_back(47);  // 5
	vec.push_back(89);  // 6
	vec.push_back(-56); // 7
	vec.push_back(12);  // 8
	vec.push_back(78);  // 9
	vec.push_back(-99); // 10
	vec.push_back(0);   // 11
	vec.push_back(45);  // 12
	vec.push_back(-67); // 13
	vec.push_back(33);  // 14
	vec.push_back(19);  // 15
	vec.push_back(88);  // 16
	vec.push_back(-42); // 17
	vec.push_back(73);  // 18
	try {
		int pos = easyfind(vec, -56) + 1;
		std::cout << "Found at position: " << pos << std::endl;
	} catch (const std::exception& e)
	{
		std::cerr << "Not found" << std::endl;
	}
}
