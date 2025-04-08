/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:10:26 by pepaloma          #+#    #+#             */
/*   Updated: 2025/04/08 12:00:44 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
/* 	using std::stack<T>::c; // c is the protected container inside std::stack
 */
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	
	// Default constructor
	MutantStack() : std::stack<T, Container>() {}

	// Copy constructor
	MutantStack(const MutantStack& src) : std::stack<T, Container>(src) {}

	// Assignment operator
	MutantStack& operator=(const MutantStack& rhs) {
		if (this != &rhs) {
			std::stack<T, Container>::operator=(rhs);
		}
		return *this;
	}

	// Destructor
	~MutantStack() {}

	// Iterator access
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};
