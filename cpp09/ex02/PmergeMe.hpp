/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 18:38:23 by kikwasni         ###   ########.fr       */
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
	
	public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	int parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
	void print_before(std::vector<int>& vec);
	void print_after(std::vector<int>& vec);
	void sort_vector_pairs(std::vector<int>& vec);
	void insert_remaining_vector(std::vector<int>& min_list, int last);
	void sort_main_vector(std::vector<int>& vec);
};



#endif