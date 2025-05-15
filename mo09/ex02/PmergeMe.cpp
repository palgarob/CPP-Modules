/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/15 17:14:44 by pepaloma         ###   ########.fr       */
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

/// Jacobsthal reorder

void PmergeMe::List::jacobsthalReorder() {
	List remainders_unordered = *this;
	List aux;
	this->clear();
	List::iterator it = remainders_unordered.begin();
	for (int i = 0; it != remainders_unordered.end(); it++, i++)
	{
		if (i == 2 || !isJacobsthal(i))
			aux.push_back(*it);
		else
			this->push_back(*it);
	}
	this->insert(this->end(), aux.begin(), aux.end());
	/* List remainders_unordered = *this;
	List::iterator it = remainders_unordered.begin();
	this->clear();
	int i = 0;
	while (true) {
		if (i == 2) {i++; continue;}
		int jacob_num = jacobsthal(i);
		for (; jacob_num > 0; jacob_num--, it++);
		this->push_back(*it);
		i++;
		if (jacobsthal(i) >= static_cast<int>(remainders_unordered.size()))
			break;
	}
	it = remainders_unordered.begin();
	for (i = 0; it != remainders_unordered.end(); it++, i++)
	{
		if (isJacobsthal(i))
			continue;
		this->push_back(*it);
	} */
}

void PmergeMe::Vector::jacobsthalReorder() 
{
	Vector remainders_unordered = *this;
	Vector aux;
	this->clear();
	for (int i = 0; i < static_cast<int>(remainders_unordered.size()); i++)
	{
		if (i == 2 || !isJacobsthal(i))
			aux.push_back(remainders_unordered[i]);
		else
			this->push_back(remainders_unordered[i]);
	}
	this->insert(this->end(), aux.begin(), aux.end());
}
/// merge insert vector

void PmergeMe::Vector::mergeInsertSort() {
	Vector highest;
	Vector remainder;
	Vector::iterator current = this->begin();
	Vector::iterator next = current;
	if (next != this->end()) next++;
	while (current != this->end())
	{
		if (next == this->end()) break;
		highest.push_back(std::max(*current, *next));
		remainder.push_back(std::min(*current, *next));
		if (current != this->end()) current++;
		if (current != this->end()) current++;
		if (next != this->end()) next++;
		if (next != this->end()) next++;
	}
	
	if (highest.size() > 2)
		highest.mergeInsertSort();
	else
	{
		if (highest.front() > highest.back())
		std::swap(highest.front(), highest.back());
	}
	remainder.jacobsthalReorder();
	for (Vector::const_iterator it = remainder.begin(); it != remainder.end(); it++)
	{
		Vector::iterator pos;
		pos = std::lower_bound(highest.begin(), highest.end(), *it);
		highest.insert(pos, *it);
	}
	if (this->size() % 2 == 1)
	{
		Vector::iterator pos;
		pos = std::lower_bound(highest.begin(), highest.end(), this->back());
		highest.insert(pos, this->back());
	}
	this->clear();
	*this = highest;
}

/// merge insert list

void PmergeMe::List::mergeInsertSort() {
	List highest;
	List remainder;
	List::iterator current = this->begin();
	List::iterator next = current;
	if (next != this->end()) next++;
	while (current != this->end())
	{
		if (next == this->end()) break;
		highest.push_back(std::max(*current, *next));
		remainder.push_back(std::min(*current, *next));
		if (current != this->end()) current++;
		if (current != this->end()) current++;
		if (next != this->end()) next++;
		if (next != this->end()) next++;
	}
	if (highest.size() > 2)
		highest.mergeInsertSort();
	else
	{
		if (highest.front() > highest.back())
		std::swap(highest.front(), highest.back());
	}
	remainder.jacobsthalReorder();
	for (List::iterator it = remainder.begin(); it != remainder.end(); it++)
	{
		List::iterator pos;
		pos = std::lower_bound(highest.begin(), highest.end(), *it);
		highest.insert(pos, *it);
	}
	if (this->size() % 2 == 1)
	{
		List::iterator pos;
		pos = std::lower_bound(highest.begin(), highest.end(), this->back());
		highest.insert(pos, this->back());
	}
	this->clear();
	*this = highest;
}
