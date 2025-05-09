/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/09 15:40:07 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

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
		this->clear(); // Clear current contents
		this->insert(this->begin(), rhs.begin(), rhs.end()); // Copy contents from rhs
	}
	return *this;
}


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

void PmergeMe::Vector::mergeInsertSort() {
	std::size_t size = this->size();
	/* for (size_t i = 0; i < this->size(); i++)
	{
		std::cout << this->operator[](i) << std::endl;
	} */
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
		lowest.mergeInsertSort();
		std::merge(greatest.begin(), greatest.end(), lowest.begin(), lowest.end(), this->begin());
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


void PmergeMe::List::mergeInsertSort() {
	std::size_t size = this->size();
	/* for (size_t i = 0; i < this->size(); i++)
	{
		std::cout << this->operator[](i) << std::endl;
	} */
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
		lowest.mergeInsertSort();
		std::merge(greatest.begin(), greatest.end(), lowest.begin(), lowest.end(), this->begin());
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

void PmergeMe::Vector::FJJ() {
	
}

int	PmergeMe::jacobsthal(int n)
{
	if (n == 0) return 0;
	i(n ==)
}
