/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:01 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/09 16:45:29 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Driss", 6);
		std::cout << b1 << std::endl;
		Form F1("Formulaire1", 5, 15);
		std::cout << F1 << std::endl;
		b1.signForm(F1);
		std::cout << F1 << std::endl;
		b1.increment();
		std::cout << b1 << std::endl;
		b1.signForm(F1);
		std::cout << F1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
