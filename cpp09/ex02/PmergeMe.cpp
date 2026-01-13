/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:24 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/13 14:12:41 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->vec = other.vec;
	this->deq = other.deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseArguments(int argc, char **argv)
{
	int i = 1;
	char *endptr;
	if (argc < 2)
		throw std::runtime_error("Error");
	std::set<int> seenNumbers;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			throw std::runtime_error("Error");
		int j = 0;
		while (argv[i][j] != '\0')
		{
			if (!isdigit(argv[i][j]))
				throw std::runtime_error("Error");
			j++;
		}
		long number = strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw std::runtime_error("Error");
		if (number > 2147483647 || number <= 0)
			throw std::runtime_error("Error");
		if (!seenNumbers.insert(number).second)
			throw std::runtime_error("Error");
		this->vec.push_back(number);
		this->deq.push_back(number);
		i++;
	}
	return (1);
}

void PmergeMe::print_before() const
{
	size_t i = 0;
	size_t n = this->vec.size();
	std::cout << "Before:  ";
	if (n == 5)
	{
		while (i < 5)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
	}
	else if (n > 5)
	{
		while (i < 5)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
		std::cout << "[...]";
	}
	else
	{
		while (i < n)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::print_after() const
{
	size_t i = 0;
	size_t n = this->vec.size();
	std::cout << "After:  ";
	if (n == 5)
	{
		while (i < 5)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
	}
	else if (n > 5)
	{
		while (i < 5)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
		std::cout << "[...]";
	}
	else
	{
		while (i < n)
		{
			std::cout << this->vec[i] << " ";
			i++;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::insertionSortVector(int left, int right)
{
	int key = 0;
	int i = left +1;
	while(i <= right)
	{
		key = this->vec[i];
		int j = i - 1;
		while(j >= left && vec[j] > key)
		{
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = key;
		i++;
	}
}

void PmergeMe::mergeVector(int left, int mid, int right)
{
	std::vector<int> l(vec.begin() + left, vec.begin() + mid + 1);
	std::vector<int> r(vec.begin() + mid + 1, vec.begin() + right + 1);

	size_t i = 0;
	size_t j = 0;
	int k = left;

	while(i < l.size() && j < r.size())
	{
		if(l[i] <= r[j])
		{
			this->vec[k] = l[i];
			i++;
		}
		else
		{
			this->vec[k] = r[j];
			j++;
		}
		k++;
	}
	while(i < l.size())
	{
		vec[k] = l[i];
		i++;
		k++;
	}
	while(j < r.size())
	{
		vec[k] = r[j];
		j++;
		k++;
	}
}
void PmergeMe::mergeInsertSortVector(int left, int right)
{
	if((right - left + 1) < 10 )
	{
		insertionSortVector(left, right);
		return;
	}
	int mid = (left + right) / 2;
	mergeInsertSortVector(left, mid);
	mergeInsertSortVector(mid +1, right);
	mergeVector(left, mid, right);
}

void PmergeMe::sortVector()
{
	int size = this->vec.size();
	if(this->vec.size() <= 1)
		return;
	mergeInsertSortVector(0, size - 1);
}