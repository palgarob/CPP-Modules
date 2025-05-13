/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/13 14:50:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

/// Vector

PmergeMe::Vector::Vector() : PmergeMe::Sortable<std::vector<unsigned> >() {}
PmergeMe::Vector::~Vector() {}

PmergeMe::Vector::Vector(const PmergeMe::Vector& src) : PmergeMe::Sortable<std::vector<unsigned> >()
{
	*this = src;
}

PmergeMe::Vector& PmergeMe::Vector::operator=(const PmergeMe::Vector& rhs)
{
	if (&rhs != this)
	{
		this->clear();
		this->insert(this->begin(), rhs.begin(), rhs.end());
	}
	return *this;
}

/// List

PmergeMe::List::List() : PmergeMe::Sortable<std::list<unsigned> >() {}
PmergeMe::List::~List() {}

PmergeMe::List::List(const PmergeMe::List& src) : PmergeMe::Sortable<std::list<unsigned> >()
{
	*this = src;
}

PmergeMe::List& PmergeMe::List::operator=(const PmergeMe::List& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->insert(this->begin(), rhs.begin(), rhs.end());
	}
	return *this;
}

/// merge insert vector

void PmergeMe::Vector::mergeInsertSort() {
	std::size_t size = this->size();
	if (size > 2)
	{
		Vector greatest;
		Vector lowest;
		Vector::iterator current = this->begin();
		Vector::iterator next = current; next++;
		while (current != this->end())
		{
			if (next == this->end())
			{
				greatest.push_back(*current);
				break ;
			}
			greatest.push_back(std::max(*current, *next));
			lowest.push_back(std::min(*current, *next));
			current++; current++;
			next++; next++;
		}

		greatest.mergeInsertSort();

		std::vector<int> sequence = generate_jacobsthal_order<std::vector<int> >(lowest.size());
		for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			std::vector<unsigned>::iterator pos = std::lower_bound(greatest.begin(), greatest.end(), lowest[*it]);
			greatest.insert(pos, lowest[*it]);
		}
		if (this->size() % 2 == 1)
		{
			std::vector<unsigned>::iterator pos = std::lower_bound(greatest.begin(), greatest.end(), lowest.back());
			greatest.insert(pos, lowest.back());
		}
		return ;
	}
	if (size == 2)
	{
		if (this->isSorted())
			return ;
		else
		{
			std::swap(this->operator[](0), this->operator[](1));
			return ;
		}
	}
	if (size == 1)
		return ;

	this->mergeInsertSort();
}

/// merge insert list

void PmergeMe::List::mergeInsertSort() {
	std::size_t size = this->size();
	if (size > 2)
	{
		List greatest;
		List lowest;
		List::iterator current = this->begin();
		List::iterator next = current; next++;
		while (current != this->end())
		{
			if (next == this->end())
			{
				greatest.push_back(*current);
				break ;
			}
			greatest.push_back(std::max(*current, *next));
			lowest.push_back(std::min(*current, *next));
			current++; current++;
			next++; next++;
		}

		greatest.mergeInsertSort();

		std::list<int> sequence = generate_jacobsthal_order<std::list<int> >(lowest.size());
		std::cout << sequence.size() << std::endl;
		std::list<int>::const_iterator it = sequence.begin();
		for (
			;
			it != sequence.end(); 
			it++
		)
		{
			std::list<unsigned>::const_iterator it2 = lowest.begin(); for (unsigned i = 0; i < *it2; it2++);
			std::list<unsigned>::iterator pos;
			pos = std::lower_bound(greatest.begin(), greatest.end(), *it2);
			greatest.insert(pos, *it2);
		}
		if (this->size() % 2 == 1)
		{
			std::list<unsigned>::iterator pos = std::lower_bound(greatest.begin(), greatest.end(), lowest.back());
			greatest.insert(pos, lowest.back());
		}
		return ;
	}
	if (size == 2)
	{
		if (this->isSorted())
			return ;
		else
		{
			List::iterator first = this->begin();
			List::iterator second = first; second++;
			std::swap(*first, *second);
			return ;
		}
	}
	if (size == 1)
		return ;

	this->mergeInsertSort();
}
