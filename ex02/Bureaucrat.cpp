/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:06 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/09 16:53:06 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) : _name(cpy._name), _grade(cpy._grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

const std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low!";
}

void Bureaucrat::increment(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signAForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << f.getName() << " signed " << _name << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << f.getName() << " couldn't sign " << _name << " because "<< e.what() << std::endl;
	}
}
