/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:37:30 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 17:28:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signedBool;
	const int _signGrade;
	const int _execGrade;

public:
	AForm();
	virtual ~AForm();
	AForm(const AForm&);
	AForm& operator=(const AForm&); 

	AForm(const std::string&, int, int);
	const std::string& getName() const;
	bool getSignedBool() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat& signer);
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class NotSigned : public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
