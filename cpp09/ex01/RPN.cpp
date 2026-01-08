/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:03 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/08 17:18:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN *other) 
{
	*this = other;
}

RPN &RPN::operator=(onst RPN *other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

RPN::~RPN() {};

