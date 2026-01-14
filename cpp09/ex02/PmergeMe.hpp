/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/14 10:27:54 by kikwasni         ###   ########.fr       */
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
	void merge_Insert_Sort_Vector(int left, int right);
	void sort_Vector();
	void measure_Time_For_Vector();
	//algorithm for deque
	void insertion_Sort_Deque(int left, int right);
	void merge_Deque(int left, int mid, int right);
	void merge_Insert_Sort_Deque(int left, int right);
	void sort_Deque();
};

#endif