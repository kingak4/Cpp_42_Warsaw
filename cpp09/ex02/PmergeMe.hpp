/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:28 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/12 11:44:14 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include PMERGEME_HPP
# define PMERGEME_HPP

#include <vector> 
#include <deque>
#include <iostream> 
#include <sstream>
#include <chrono> 
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>

class PmergeMe 
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	public:
		int parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
}



#endif