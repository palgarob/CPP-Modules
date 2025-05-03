/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:11 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/03 14:31:39 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>

namespace PmergeMe
{
	class Vector : public std::vector<unsigned> {
		private:
			bool isSorted();
			
		public:
			Vector();
			~Vector();
			Vector(const Vector& src);
			Vector& operator=(const Vector& rhs);

			void mergeInsertSort();
	};

	template <typename Container>
	void printNumbers(const Container& container)
	{
		typename Container::const_iterator current = container.begin();
		typename Container::const_iterator next = current; next++;
		for (; next != container.end(); current++, next++)
			std::cout << "	" << *current;
		std::cout << "	"  << *current;
	}
}
