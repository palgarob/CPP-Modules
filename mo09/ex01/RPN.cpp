/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:03:55 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/01 02:08:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

void RPN::result() const
{
	if (this->operands.size() != 1)
		throw(RPN::StackStillFull());
	else
		std::cout << this->operands.top() << std::endl;
}

void RPN::newInput(char input)
{
	if (!std::isdigit(input))
		this->operate(input);
	else
		this->operands.push(input - '0');
}

void RPN::operate(char o)
{
	if (this->operands.size() < 2)
		throw(RPN::NotEnoughOperands());
	int new_element;
	switch (o) {
		case '*':
			new_element = this->operands.top();
			this->operands.pop();
			new_element *= this->operands.top();
			this->operands.pop();
			break ;
		case '+':
			new_element = this->operands.top();
			this->operands.pop();
			new_element += this->operands.top();
			this->operands.pop();
			break ;
		case '-':
			new_element = this->operands.top();
			this->operands.pop();
			new_element -= this->operands.top();
			this->operands.pop();
			break ;
		case '/':
			new_element = this->operands.top();
			this->operands.pop();
			new_element /= this->operands.top();
			this->operands.pop();
			break ;
		default :
			throw(RPN::InputError());
	}
	this->operands.push(new_element);
}

const char* RPN::StackStillFull::what() const throw()
{
	return ("Error: StackStillFull");
}

const char* RPN::NotEnoughOperands::what() const throw()
{
	return ("Error: NotEnoughOperands");
}

const char* RPN::InputError::what() const throw()
{
	return ("Error: InputError");
}
