/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:06 by drabarza          #+#    #+#             */
/*   Updated: 2025/08/28 13:02:11 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) : _name(name), _state(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _state(cpy._state), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec)
{}

AForm::~AForm()
{}

const AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_state = rhs._state;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << rhs.getName() << ", AForm grade sign " << rhs.getGradeSign() << " and grade exec " << rhs.getGradeExec() << " sign : " << (rhs.getState() ? "yes" : "no") << ".";
	return os;
}

const std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getState(void) const
{
	return _state;
}

int AForm::getGradeSign(void) const
{
	return _gradeSign;
}

int AForm::getGradeExec(void) const
{
	return _gradeExec;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_state = true;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}
