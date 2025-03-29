/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:27:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/29 15:06:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

/// Constructors

template<typename T>
Array<T>::Array() : _n(0), _first_element_ptr(NULL) {}

template<typename T>
Array<T>::Array(const Array& src)
{
	*this = src;
}

template<typename T>
Array<T>::Array(std::size_t n) : _n(n)
{
	this->_first_element_ptr = new T[this->size()];
}

/// Others

template<typename T>
Array<T>::~Array() {delete [] _first_element_ptr;}

template<typename T>
const T& Array<T>::operator[](std::size_t i) const
{
	if (i > this->size())
		throw std::exception();
	return _first_element_ptr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		this->~Array();
		this->_n = rhs.size();
		this->_first_element_ptr = new T[rhs.size()];
		for (std::size_t i=0;i < this->_n; i++)
			this->_first_element_ptr[i] = rhs[i];
	}
	return *this;
}

template<typename T>
std::size_t Array<T>::size() const
{
	return this->_n;
}

template<typename T>
void Array<T>::setValue(std::size_t i, const T& value)
{
	this->_first_element_ptr[i] = value;
}

#endif
