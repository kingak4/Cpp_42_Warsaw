/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:24 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 14:54:46 by kikwasni         ###   ########.fr       */
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

void PmergeMe::print_before(std::vector<int>& vec)
{
	size_t i = 0;
	size_t n = vec.size();
	std::cout << "Before:  ";
	if (n == 5)
	{
		while(i < 5)
		{
			std::cout << vec[i] << " ";
			i++;
		}
	}
	else if (n > 5)
	{
		while(i < 5)
		{
			std::cout << vec[i] << " ";
			i++;
		}
		std::cout << "[...]";
	}
	else
	{
		while(i < n)
		{
			std::cout << vec[i] << " ";
			i++;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::print_after(std::vector<int>& vec)
{
	size_t i = 0;
	size_t n = vec.size();
	std::cout << "After:  ";
	if (n == 5)
	{
		while(i < 5)
		{
			std::cout << vec[i] << " ";
			i++;
		}
	}
	else if (n > 5)
	{
		while(i < 5)
		{
			std::cout << vec[i] << " ";
			i++;
		}
		std::cout << "[...]";
	}
	else
	{
		while(i < n)
		{
			std::cout << vec[i] << " ";
			i++;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::sort_vector_pairs(std::vector<int>& vec)
{
	std::vector<int> min_list;
	std::vector<int> max_list;
	int i = 0;
	while(i < vec.size() - 1)
	{
		int a = vec[i];
		int b = vec[i +1];
		if(a > b)
		{
			int tmp;
			tmp = a;
			a = b;
			b = tmp;
			min_list.push_back(a);
			max_list.push_back(b);
		}
		else
		{
			min_list.push_back(a);
			max_list.push_back(b);
		}
		i++;
	}
	if(vec.size() % 2 != 0)
	{
		int last = vec.back();
		// wywołaj funkje insert_remaining
	}
	
}

void PmergeMe::insert_remaining_vector(std::vector<int>& min_list, int last)
{
	
	
	
}

