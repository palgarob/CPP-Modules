/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:19:12 by pepaloma          #+#    #+#             */
/*   Updated: 2025/05/01 01:53:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <exception>
#include <cctype>
#include <iostream>

class RPN {
	private:
		std::stack<int> operands;
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);

		void operate(char o);
	public:
		RPN();
		~RPN();

		void newInput(char input);
		void result() const;
		
		class StackStillFull : public std::exception {
			const char* what() const throw();
		};
		class NotEnoughOperands : public std::exception {
			const char* what() const throw();
		};
		class InputError : public std::exception {
			const char* what() const throw();
		};
};
