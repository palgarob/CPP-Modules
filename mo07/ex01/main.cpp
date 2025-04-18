/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:27:56 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 10:30:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main()
{
	double a[3] = {1.2, 2, 3};
	std::string s[4] = {
		"holaaaa",
		"adiooos",
		"kaixooo",
		"buenass"
	};
	iter(a, 3, foo<double>);
	std::cout << "----------" << std::endl;
	iter(s, 4, foo<std::string>);
}
