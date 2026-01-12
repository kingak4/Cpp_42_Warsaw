/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:24 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 12:54:20 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq)
{
	int i  = 1;
	char* endptr;
	if(argc < 2)
	{
		throw std::runtime_error("Error");
		return(0);
	}
	std::set<int> seenNumbers;
	while(i < argc)
	{
		if(argv[i][0] == '\0')
			throw std::runtime_error("Error");
		int j = 0;
		while(argv[i][j] != '\0')
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Error");
			j++;
		}
		long number = strtol(argv[i], &endptr, 10);
		if(*endptr != '\0')
			throw std::runtime_error("Error");
		if(number > 2147483647 || number <= 0)
			throw std::runtime_error("Error");
		if (!seenNumbers.insert(number).second)
			throw std::runtime_error("Error");
		vec.push_back(number);
		deq.push_back(number);
		i++;
	}
	return(1);
}
