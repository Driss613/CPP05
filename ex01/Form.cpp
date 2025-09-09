/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:06 by drabarza          #+#    #+#             */
/*   Updated: 2025/08/28 13:02:11 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSign, int gradeExec) : _name(name), _state(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& cpy) : _name(cpy._name), _state(cpy._state), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec)
{}

Form::~Form()
{}

const Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		_state = rhs._state;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << rhs.getName() << ", form grade sign " << rhs.getGradeSign() << " and grade exec " << rhs.getGradeExec() << " sign : " << (rhs.getState() ? "yes" : "no") << ".";
	return os;
}

const std::string Form::getName(void) const
{
	return _name;
}

bool Form::getState(void) const
{
	return _state;
}

int Form::getGradeSign(void) const
{
	return _gradeSign;
}

int Form::getGradeExec(void) const
{
	return _gradeExec;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_state = true;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}
