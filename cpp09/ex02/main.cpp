/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:32:14 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/13 12:20:14 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe p;
	try
	{
		p.parseArguments(argc, argv, vec, deq);
		p.print_before(vec);
		p.sort_main_vector(vec);
		p.print_after(vec);
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
