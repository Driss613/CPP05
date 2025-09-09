/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:56:47 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/09 17:01:29 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string _name;
		bool _state;
		const int _gradeSign;
		const int _gradeExec;
	public :
		ShrubberyCreationForm(const std::string& name, int gradeSign, int gradeExec);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();
		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
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

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs);
