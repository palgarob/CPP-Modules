/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:45:41 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/20 01:56:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data d = {4};
	uintptr_t ptr;

	std::cout << &d << std::endl;
	ptr = Serializer::serialize(&d);
	std::cout << ptr << std::endl;
	std::cout << Serializer::deserialize(ptr) << std::endl;
}
