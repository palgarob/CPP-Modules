/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:10:50 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 17:15:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int _grade;
		void checkRange() const;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);

		Bureaucrat(const std::string&, int);
		const std::string&	getName() const;
		int	getGrade() const;
		void	downGrade();
		void	upGrade();
		void	signForm(AForm&) const;
		void executeForm(const AForm& form) const;

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
