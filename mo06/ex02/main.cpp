/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:59:29 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/31 09:56:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	int randomValue = rand() % 3;
	if (randomValue == 0) return new A();
	if (randomValue == 1) return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p)
{
	try {
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		p = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		p = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

#include "Base.hpp"
#include <iostream>

int main() {
	Base* obj = generate();
	std::cout << "Identifying using pointer: ";
	identify(obj);

	std::cout << "Identifying using reference: ";
	identify(*obj);

	delete obj;
	return 0;
}
