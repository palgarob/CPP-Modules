/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:01:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/03 19:49:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <cmath>
#include <algorithm>
#include <iostream>

Span::Span(unsigned int n) : _N(n) {}
Span::~Span() {};

Span& Span::operator=(const Span& rhs)
{
	(void)rhs;
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if (this->lst.size() >= this->_N)
		throw std::exception();
	this->lst.push_back(n);
}

long Span::shortestSpan() const
{
	long min = std::numeric_limits<long>::max();
	for (std::list<int>::const_iterator current = this->lst.begin(); current != this->lst.end(); ++current) {
		for (std::list<int>::const_iterator it = current; it != this->lst.end(); ++it) {
			if (current != it && abs(*current - *it) < min)
					min = abs(*current - *it);
		}
	}
	return min;
}

long Span::longestSpan() const
{
	long max = 0;
	for (std::list<int>::const_iterator current = this->lst.begin(); current != this->lst.end(); ++current) {
		for (std::list<int>::const_iterator it = current; it != this->lst.end(); ++it) {
			if (current != it && abs(*current - *it) > max)
				max = abs(*current - *it);
		}
	}
	return max;
}

static void printIt(int i)
{
	std::cout << i << std::endl;
}

void Span::printList() const
{
	std::for_each(this->lst.begin(), this->lst.end(), printIt);
}
