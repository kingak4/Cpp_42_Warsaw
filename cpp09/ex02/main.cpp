/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:32:14 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/14 10:48:18 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe p;
	try
	{
		p.parseArguments(argc, argv);
		p.print_before();
		p.measure_Time_For_Vector();
		p.measure_Time_For_Deque();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
