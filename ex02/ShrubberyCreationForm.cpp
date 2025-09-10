/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:56:44 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/10 17:05:06 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm::AForm()
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : _target(cpy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		_state = rhs._state;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs)
{
	os << rhs.getName() << ", ShrubberyCreationForm grade sign " << rhs.getGradeSign() << " and grade exec " << rhs.getGradeExec() << " sign : " << (rhs.getState() ? "yes" : "no") << ".";
	return os;
}
