/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/03 16:02:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::Vector::Vector() : std::vector<unsigned>() {}
PmergeMe::Vector::~Vector() {}

PmergeMe::Vector::Vector(const PmergeMe::Vector& src) : std::vector<unsigned>()
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

bool PmergeMe::Vector::isSorted()
{
	Vector::iterator current = this->begin();
	Vector::iterator next = current;
	next++; if (next == this->end()) return true;
	for (; next != this->end(); current++, next++)
	{
		if (*next < *current)
			return false;
	}
	return (true);
}
