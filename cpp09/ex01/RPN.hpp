/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:14 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/09 12:46:37 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
	private:
		std::stack<int> stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		int isNumber(std::string token);
		int isOperator(std::string token);
		int validateToken(std::string token);
		void applyOperator(std::string oper);
		void processToken(std::string token);
		int execute(std::string token);
};

#endif