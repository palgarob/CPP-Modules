/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:11 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/09 15:35:59 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

namespace PmergeMe
{
	template <typename Container>
	class Sortable : public Container {
		private:
			Sortable(const Sortable& src);
			Sortable& operator=(const Sortable& rhs);
		protected:
			bool isSorted() {
				typename Container::iterator current = this->begin();
				typename Container::iterator next = current;
				next++; if (next == this->end()) return true;
				for (; next != this->end(); current++, next++)
				{
					if (*next < *current)
						return false;
				}
				return (true);
			}
			Sortable() {}
			~Sortable() {}
		public:
			virtual void mergeInsertSort() = 0;
			virtual void FJJ() = 0;
	};

	class Vector : public Sortable<std::vector<unsigned> > {
		public:
			Vector();
			~Vector();
			Vector(const Vector& src);
			Vector& operator=(const Vector& rhs);

			void mergeInsertSort();
			void FJJ();
	};

	class List : public Sortable<std::list<unsigned> > {
		public:
			List();
			~List();
			List(const List& src);
			List& operator=(const List& rhs);

			void mergeInsertSort();
			void FJJ();
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

	int jacobsthal(int n);
}
