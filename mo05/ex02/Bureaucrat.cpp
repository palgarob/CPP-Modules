/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:31 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 20:44:52 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

void Bureaucrat::checkRange() const
{
	if (this->getGrade() < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->getGrade() > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy constructor called: " << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat name constructor called" << std::endl;
	this->checkRange();
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::downGrade()
{
	this->_grade = this->getGrade() + 1;
	this->checkRange();
	std::cout << "You've been demoted..." << std::endl;
}

void	Bureaucrat::upGrade()
{
	this->_grade = this->getGrade() - 1;
	this->checkRange();
	std::cout << "You've been promoted!" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException: No bureaucrat above 1!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException: No bureaucrat below 150!");
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}


