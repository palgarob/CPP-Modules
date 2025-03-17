/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:14:29 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/17 12:33:28 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
	std::string _target;
	/// @brief Subject requires OCCF, but also one constructor. So the
	/// solution is make them private and don't define them
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);

	public:

	/// @brief Constructor.
	/// @param target For initialization.
	PresidentialPardonForm(const std::string& target);

	/// @brief Overload function.
	/// @param  rhs src.
	/// @return The lhs argument.
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	
	/// @brief Destructor
	~PresidentialPardonForm();

	/// @brief Executes the form's orders
	/// @param  executor of the form's orders
	void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;
};

#endif
