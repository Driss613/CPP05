/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:56:47 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/10 17:02:26 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;
	public :
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();
		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		void	execute(const Bureaucrat& executor);
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs);
