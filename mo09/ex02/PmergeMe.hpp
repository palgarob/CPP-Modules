/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:11 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/20 12:27:28 by pepaloma         ###   ########.fr       */
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
					if (*next > *current) /// hiugfdsrardhfgjklbjvghcfgdfgh
						return false;
				}
				return (true);
			}
			Sortable() {}
			~Sortable() {}
		public:
			virtual void mergeInsertSort() = 0;
	};

	class Vector : public Sortable<std::vector<unsigned> > {
		public:
			Vector();
			~Vector();
			Vector(const Vector& src);
			Vector& operator=(const Vector& rhs);

			void mergeInsertSort();
			void jacobsthalReorder();
	};

	class List : public Sortable<std::list<unsigned> > {
		public:
			List();
			~List();
			List(const List& src);
			List& operator=(const List& rhs);

			void mergeInsertSort();
			void jacobsthalReorder();
	};

	template <typename Container>
	void printNumbers(const Container& container)
	{
		typename Container::const_iterator current = container.begin();
		typename Container::const_iterator next = current; next++;
		for (int i = 0; next != container.end(); current++, next++, i++)
		{
			if (i > 10)
			{
				std::cout << "	[...]" << std::endl;
				return ;
			}
			std::cout << "	" << *current;
		}
		std::cout << "	"  << *current;
	}
}

double jacobsthal(int n);
bool isJacobsthal(int n);
double benchmark_vector(std::vector<std::string> args, PmergeMe::Vector& result);
double benchmark_list(std::vector<std::string> args, PmergeMe::List& result);
void parse_list(const std::vector<std::string> args, PmergeMe::List& v);
void parse_vector(const std::vector<std::string> args, PmergeMe::Vector& v);
