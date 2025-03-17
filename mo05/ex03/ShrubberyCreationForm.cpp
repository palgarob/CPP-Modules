/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:05:43 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/15 20:50:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("SCF", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm name constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	rhs.getExecGrade(); ///to prevent warninga
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSignedBool())
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::string target = this->getTarget();
	std::ofstream ofs (target.append("_shrubbery").c_str());
	ofs << "    . . . " << std::endl;
	ofs << " .        .  .     ..    . " << std::endl;
	ofs << " .                 .         .  . " << std::endl;
	ofs << "                 . " << std::endl;
	ofs << "             .                .. " << std::endl;
	ofs << " .          .            .              . " << std::endl;
	ofs << " .            '.,        .               . " << std::endl;
	ofs << " .              'b      * " << std::endl;
	ofs << "  .              '$    #.                .. " << std::endl;
	ofs << " .    .           $:   #:               . " << std::endl;
	ofs << " ..      .  ..      *#  @):        .   . . " << std::endl;
	ofs << "            .     :@,@):   ,.**:'   . " << std::endl;
	ofs << " .      .,         :@@*: ..**'      .   . " << std::endl;
	ofs << "         '#o.    .:(@'.@*'  . " << std::endl;
	ofs << " .  .       'bq,..:,@@*'   ,*      .  . " << std::endl;
	ofs << "            ,p$q8,:@)'  .p*'      . " << std::endl;
	ofs << "     '  . '@@Pp@@*'    .  . " << std::endl;
	ofs << "  .  . ..    Y7'.'     .  . " << std::endl;
	ofs << "               :@):. " << std::endl;
	ofs << "              .:@:'. " << std::endl;
	ofs << "            .::(@:.      -Sam Blumenstein- " << std::endl;
	ofs.close();
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return _target;
};
