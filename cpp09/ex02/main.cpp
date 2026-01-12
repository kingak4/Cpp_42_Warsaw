/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:32:14 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 13:14:51 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	std::vector<int> vec;
	std::deque<int> deq;
	PmergeMe p;
	try
	{
		p.parseArguments(argc, argv, vec, deq);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}