/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:01:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/08 14:39:19 by pepaloma         ###   ########.fr       */
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
	if (this->vec.size() >= this->_N)
		throw std::exception();
	this->vec.push_back(n);
}

long Span::shortestSpan() const
{
	long min = std::numeric_limits<long>::max();
	for (std::vector<int>::const_iterator current = this->vec.begin(); current != this->vec.end(); ++current) {
		for (std::vector<int>::const_iterator it = current; it != this->vec.end(); ++it) {
			if (current != it && abs(*current - *it) < min)
					min = abs(*current - *it);
		}
	}
	return min;
}

long Span::longestSpan() const
{
	long max = 0;
	for (std::vector<int>::const_iterator current = this->vec.begin(); current != this->vec.end(); ++current) {
		for (std::vector<int>::const_iterator it = current; it != this->vec.end(); ++it) {
			if (current != it && abs(*current - *it) > max)
				max = abs(*current - *it);
		}
	}
	return max;
}

static void printIt(int i)
{
	std::cout << i << " ";
}

void Span::printList() const
{
	std::for_each(this->vec.begin(), this->vec.end(), printIt);
	std::cout << std::endl;
}

static std::vector<int> generate_numbers_pool()
{
	srand(time(NULL));
	int size = 1000000;
	std::vector<int> pool;

	for (int i = 0; i < size; i++) {
		pool.push_back(i);
	}

	for (int i = size - 1; i >= 0; i--) {
		int j = rand() % (i + 1);
		int temp = pool[i];
		pool[i] = pool[j];
		pool[j] = temp;
	}
	return (pool);
}

void Span::fillVector()
{
	std::vector<int> pool = generate_numbers_pool();
	for (unsigned i = 0; i < this->_N; i++)
	{
		this->addNumber(pool[i]);
	}
}
