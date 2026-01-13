/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/13 15:42:04 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	// parsing and printing result 
	int parseArguments(int argc, char **argv);
	void print_before() const;
	void print_after() const;
	// algorithm for vector 
	void insertion_Sort_Vector(int left, int right);
	void merge_Vector(int left, int mid, int right);
	void merge_Insert_Sort_Vectorr(int left, int right);
	void sort_Vector();
	//algorithm for deque
	void insertionSort_Deque(int left, int right);
	void merge_Deque(int left, int mid, int right);
	void merge_InsertSort_Deque(int left, int right);
	void sort_Deque();
};

#endif