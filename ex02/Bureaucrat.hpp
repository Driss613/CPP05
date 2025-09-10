/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:20:55 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/10 15:51:23 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
	private :
		const std::string _name;
		int _grade;
	public :
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& cpy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);
		const std::string getName(void) const;
		int		getGrade(void) const;
		void	increment();
		void	decrement();
		void	signAForm(AForm& f);
		class GradeTooHighException : public std::exception
		{
			public :
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
			const char *what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);
#include "AForm.hpp"
