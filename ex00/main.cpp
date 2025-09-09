/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:01 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/05 11:20:58 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test1("Driss", 150);
		std::cout << test1 << std::endl;
		test1.increment();
		std::cout << test1 << std::endl;
		test1.decrement();
		std::cout << test1 << std::endl;
		test1.decrement();
		std::cout << test1 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}
