/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:32:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/08 14:33:33 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

class Span
{
	private:
	const unsigned int _N;
	std::vector<int> vec;
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
	void fillVector();
};
