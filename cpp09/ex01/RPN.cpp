/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:18:03 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/09 12:56:30 by kikwasni         ###   ########.fr       */
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

int RPN::isNumber(std::string token)
{
	if(token.length() != 1)
		return(0);
	if(!isdigit(token[0]))
		return(0);
	return(1);
}

int RPN::isOperator(std::string token)
{
	char c = token[0];

	if(token.length() != 1)
		return(0);
	if(c == '-' || c == '*' || c == '+' || c == '/')
		return(1);
	return(0);
}

int RPN::validateToken(std::string token)
{
	if(isNumber(token) == 1)
		return(1);
	else if(isOperator(token) == 1)
			return(1);
	throw std::runtime_error("Error");
	return(0);
}
void RPN::applyOperator(std::string oper)
{
	if(stack.size() < 2)
	throw std::runtime_error("Error");
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();
	int rest = 0;
	if(oper == '-')
		rest = a - b;
	else if(oper == '+')
		rest = a + b;
	else if(oper == '*')
		rest = a * b;
	else if(oper == '/')
	{
		if(b != 0)
			rest = a / b;
		else
			throw std::runtime_error("Error");
	}
	stack.push(rest);
}

void RPN::processToken(std::string token)
{
	int value = 0;
	validateToken(token);
	if(isNumber(token) == 1)
	{
		value = token[0] - '0';
		stack.push(value);
	}
	else
		applyOperator(token);
}

int RPN::execute(std::string token)
{
	std::istringstream iss(token);
	 std::string currentToken;
	while (iss >> currentToken)
		processToken(currentToken);
	if(stack.size() != 1)
		throw std::runtime_error("Error");
	int rest = stack.top();
	stack.pop();
	return(rest);
}
