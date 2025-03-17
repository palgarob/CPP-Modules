/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:37:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/15 13:41:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signedBool(false), _signGrade(70), _execGrade(20)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& src)
: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_signedBool = src._signedBool;
}

Form& Form::operator=(const Form& rhs)
{
	(void)rhs;
	return *this;
}

static void	outofRange(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string& name, int signGrade, int execGrade)
: _name(name), _signedBool(false), _signGrade(signGrade), _execGrade(execGrade)
{
	outofRange(_signGrade);
	outofRange(_execGrade);
	std::cout << "Form name constructor called" << std::endl;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getSignedBool() const {
	return _signedBool;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if ((int)bureaucrat.getGrade() > _signGrade) {
		throw Form::GradeTooLowException();
	}
	_signedBool = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
		<< ", Exec Grade: " << form.getExecGrade() << ", Signed: " << (form.getSignedBool() ? "Yes" : "No");
	return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form::GradeTooHighException: Don't try to initialize\n\
	 a form with zero or negative numbers!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form::GradeTooLowException: Either you're trying to\n\
	 initialize a form with a grade too low or you can't sign this!!";
}
