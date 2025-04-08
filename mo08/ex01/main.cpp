/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:55:42 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/03 19:44:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>

int main()
{
	int n = 4;
	srand(time(NULL));
	Span s(n);
	for (int i = 0; i < n; i++)
	{
		s.addNumber(rand());
	}
	s.printList();
	std::cout << "-------" << std::endl;
	std::cout << s.shortestSpan() << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << s.longestSpan() << std::endl;
}
