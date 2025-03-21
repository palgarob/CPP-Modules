/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:45:41 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/21 15:27:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data d = {4};
	Data* ptr = &d;
	uintptr_t raw;

	std::cout << ptr << std::endl;

	raw = Serializer::serialize(&d);

	std::cout << std::hex << raw << std::endl;

	ptr = Serializer::deserialize(raw);
	
	std::cout << ptr << std::endl;

}
