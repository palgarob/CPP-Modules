/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:14:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/11 10:16:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This module deals with
	- Ad-hoc polymorphism,
	- operator overloading
	- and the Orthodox Canonical Class Form 
*/

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
