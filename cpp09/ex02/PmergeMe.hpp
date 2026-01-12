/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 12:53:58 by kikwasni         ###   ########.fr       */
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
		int parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};



#endif