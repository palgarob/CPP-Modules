/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:37:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 17:27:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signedBool(false), _signGrade(70), _execGrade(20)
{
	std::cout << "Default Form constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(const AForm& src)
: _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	this->_signedBool = src._signedBool;
}

AForm& AForm::operator=(const AForm& rhs)
{
	(void)rhs;
	return *this;
}

static void	outofRange(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
: _name(name), _signedBool(false), _signGrade(signGrade), _execGrade(execGrade)
{
	outofRange(_signGrade);
	outofRange(_execGrade);
	std::cout << "Form name constructor called" << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getSignedBool() const {
	return _signedBool;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if ((int)bureaucrat.getGrade() > _signGrade) {
		throw AForm::GradeTooLowException();
	}
	_signedBool = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
		<< ", Exec Grade: " << form.getExecGrade() << ", Signed: " << (form.getSignedBool() ? "Yes" : "No");
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form::gradeTooHighException: Don't try to initialize\n\
	 a form with zero or negative numbers!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form::gradeTooLowException: Either you're trying to\n\
initialize a form with a grade too low or you can't sign this!!";
}

const char* AForm::NotSigned::what() const throw()
{
	return ("AForm::NotSigned: You can't execute this file\n\
because is not signed yet!");
}
