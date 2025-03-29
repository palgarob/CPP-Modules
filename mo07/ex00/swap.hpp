/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:54:50 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 12:36:57 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

template<typename T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

#endif
