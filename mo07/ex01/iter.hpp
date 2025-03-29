/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:03:41 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 12:35:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void foo(T& element)
{
	std::cout << element << std::endl;
}

template<typename T, typename F>
void iter(T *array, std::size_t n, F func)
{
	for (size_t i = 0; i < n; i++)
	{
		func(array[i]);
	}
}

#endif
