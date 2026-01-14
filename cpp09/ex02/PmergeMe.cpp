/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:24 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/14 10:28:14 by kikwasni         ###   ########.fr       */
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

// parsing and printing result 

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

// algorithm for vector 

void PmergeMe::insertion_Sort_Vector(int left, int right)
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

void PmergeMe::merge_Vector(int left, int mid, int right)
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
void PmergeMe::merge_Insert_Sort_Vector(int left, int right)
{
	if((right - left + 1) < 15 )
	{
		insertion_Sort_Vector(left, right);
		return;
	}
	int mid = (left + right) / 2;
	merge_Insert_Sort_Vector(left, mid);
	merge_Insert_Sort_Vector(mid +1, right);
	merge_Vector(left, mid, right);
}

void PmergeMe::sort_Vector()
{
	int size = this->vec.size();
	if(this->vec.size() <= 1)
		return;
	merge_Insert_Sort_Vector(0, size - 1);
}
void PmergeMe::measure_Time_For_Vector()
{
	size_t len = this->vec.size();
	clock_t start = clock();
	sort_Vector();
	clock_t end = clock();
	double time_us = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout<< "Time to process a range of " << len << " elements with std::[..] :  " << time_us << " us "<<std::endl;
}

void PmergeMe::insertion_Sort_Deque(int left, int right)
{
	int key = 0;
	int i = left +1;
	while(i <= right)
	{
		key = this->deq[i];
		int j = i - 1;
		while(j >= left && deq[j] > key)
		{
			deq[j+1] = deq[j];
			j--;
		}
		deq[j+1] = key;
		i++;
	}
}
void PmergeMe::merge_Deque(int left, int mid, int right)
{
	std::vector<int> l(deq.begin() + left, deq.begin() + mid + 1);
	std::vector<int> r(deq.begin() + mid + 1, deq.begin() + right + 1);

	size_t i = 0;
	size_t j = 0;
	int k = left;

	while(i < l.size() && j < r.size())
	{
		if(l[i] <= r[j])
		{
			this->deq[k] = l[i];
			i++;
		}
		else
		{
			this->deq[k] = r[j];
			j++;
		}
		k++;
	}
	while(i < l.size())
	{
		deq[k] = l[i];
		i++;
		k++;
	}
	while(j < r.size())
	{
		deq[k] = r[j];
		j++;
		k++;
	}
}
void PmergeMe::merge_Insert_Sort_Deque(int left, int right)
{
	if((right - left + 1) < 15 )
	{
		insertion_Sort_Deque(left, right);
		return;
	}
	int mid = (left + right) / 2;
	merge_Insert_Sort_Deque(left, mid);
	merge_Insert_Sort_Deque(mid +1, right);
	merge_Deque(left, mid, right);
}
void PmergeMe::sort_Deque()
{
	int size = this->deq.size();
	if(this->deq.size() <= 1)
		return;
	merge_Insert_Sort_Deque(0, size - 1);
}

