/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:37:30 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/15 13:41:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signedBool;
	const int _signGrade;
	const int _execGrade;
	
	public:
	/// @brief Orthodox Canonical Class Form functions
	Form();
	~Form();
	Form(const Form&);
	Form& operator=(const Form&); 
	/// OCCF

	Form(const std::string&, int, int);
	const std::string& getName() const;
	bool getSignedBool() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat&);

	/// @throws in case the grade is out of bounds
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
