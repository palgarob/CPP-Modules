/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:44:09 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 15:11:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	try {
		Array<int> a(10);
		a.setValue(5, -146);
		Array<int> b;
		b = a;
		std::cout << b[5] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Probably out of range" << std::endl;
	}
	std::cout << "--------" << std::endl;
	try {
		Array<std::string> a(10);
		a.setValue(5, "hola");
		Array<std::string> b(10);
		b.setValue(5, "adios");
		b = a;
		std::cout << b[50] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Probably out of range" << std::endl;
	}
}
