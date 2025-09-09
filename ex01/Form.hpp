/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:20:55 by drabarza          #+#    #+#             */
/*   Updated: 2025/08/28 12:58:14 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string _name;
		bool _state;
		const int _gradeSign;
		const int _gradeExec;
	public :
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& cpy);
		~Form();
		const Form& operator=(const Form& rhs);
		const std::string getName(void) const;
		bool getState(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		void beSigned(const Bureaucrat& b);
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

std::ostream& operator<<(std::ostream& os, const Form& rhs);
