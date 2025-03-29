/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:44:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 14:13:28 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>

template<typename T>
class Array
{
	private:
	std::size_t _n;
	T* _first_element_ptr;
	
	public:
	Array();
	Array(std::size_t n);
	Array(const Array& src);
	~Array();
	Array& operator=(const Array& rhs);
	std::size_t size() const;
	const T& operator[](std::size_t i) const;
	void setValue(std::size_t i, const T& value);
};

#include "Array.tpp"

#endif
