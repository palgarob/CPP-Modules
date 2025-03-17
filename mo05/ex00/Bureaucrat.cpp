/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:31 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/15 13:41:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "Bureaucrat copy constructor called: ";
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
		this->_name = rhs._name;
	}
	return *this;
}

/**
 * @fn outofRange
 * @brief Checks whether a Burocrat's grade is too high or low
*/
static void	outofRange(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	outofRange(grade);
	std::cout << "Bureaucrat name constructor called" << std::endl;
	this->_grade = grade;
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
	outofRange(this->_grade + 1);
	std::cout << "You've been demoted..." << std::endl;
	this->_grade++;
}

void	Bureaucrat::upGrade()
{
	outofRange(this->_grade + 1);
	std::cout << "You've been promoted!" << std::endl;
	this->_grade--;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}


