/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:54:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 12:35:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	const std::string _target;
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	
	public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;
};

#endif
