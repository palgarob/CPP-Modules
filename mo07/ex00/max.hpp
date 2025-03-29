/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:10 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 12:36:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_HPP
#define MAX_HPP

template<typename T>
const T& max(const T& a, const T& b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
