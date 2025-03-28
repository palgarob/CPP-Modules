/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:02:19 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/15 20:49:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	const std::string _target;
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	
	public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	~RobotomyRequestForm();
	void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;
};
