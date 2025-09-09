/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:21:01 by drabarza          #+#    #+#             */
/*   Updated: 2025/09/09 16:53:06 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Driss", 6);
		std::cout << b1 << std::endl;
		AForm F1("AFormulaire1", 5, 15);
		std::cout << F1 << std::endl;
		b1.signAForm(F1);
		std::cout << F1 << std::endl;
		b1.increment();
		std::cout << b1 << std::endl;
		b1.signAForm(F1);
		std::cout << F1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
