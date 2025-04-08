/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:42:42 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/01 17:45:49 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <list>

template<typename T>
int easyfind(const T&container, int value)
{
	typename T::const_iterator found = std::find(
		container.begin(),
		container.end(),
		value);
	if (found == container.end())
		throw std::exception();
	else return std::distance(container.begin(), found);
}
