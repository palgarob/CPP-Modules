/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:32:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/03 15:45:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>

class Span
{
	private:
	const unsigned int _N;
	std::list<int> lst;
	Span();
	Span(const Span& src);

	public:
	~Span();
	Span& operator=(const Span& rhs);
	Span(unsigned int N);
	void addNumber(unsigned int n);
	long shortestSpan() const;
	long longestSpan() const;
	void printList() const;
};
