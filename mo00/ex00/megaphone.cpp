/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:52:42 by pepaloma          #+#    #+#             */
/*   Updated: 2024/05/09 21:50:32 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(__attribute__((unused)) int argc, char **argv)
{
	argv++;
	while (argv)
	{
		char *str = *argv;
		int i = 0;
		while (str[i])
		{
			std::cout << &std::toupper(str[i]) << std::endl;
			i++;
		}
		argv++;
	}
	return (0);
}
