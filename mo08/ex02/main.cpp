/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:01:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/08 11:52:51 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<char> s;
	s.push('a');
	s.push('b');
	for (MutantStack<char>::iterator it = s.begin(); it != s.end(); it++)
		std::cout << *it << std::endl;
}
