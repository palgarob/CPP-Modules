/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:32:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 11:52:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("SCF", 75, 45), _target(target)
{
	std::cout << "RobotomyRequestForm name constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	rhs.getExecGrade(); // to silence warning
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (!this->getSignedBool())
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getExecGrade())
	{
		std::cerr << "Robotomy failed" << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been robotomized 50%% of the time" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}
