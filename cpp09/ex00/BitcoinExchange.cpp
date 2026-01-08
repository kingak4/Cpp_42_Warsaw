/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:17:56 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/08 17:18:01 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::loadDatabase(const char *filename)
{
	std::ifstream file;
	std::string line;
	std::string date;
	std::string rate_text;
	float rate = 0;

	file.open(filename);
	if (!file)
	{
		std::cerr << "Can't open data file!" << std::endl;
		return (0);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(",");
		date = line.substr(0, pos);
		rate_text = line.substr(pos + 1);
		rate = std::atof(rate_text.c_str());
		values[date] = rate;
	}
	file.close();
	return (1);
}

void BitcoinExchange::processInputFile(const char *filename)
{
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string value_text = line.substr(sep + 3);
		if (!validateInputLine(date, value_text) || value_text.empty())
		{
			float v = std::atof(value_text.c_str());
			if (v < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (v > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value = std::atof(value_text.c_str());
		float rate = getBitcoinRate(date);
		if (rate < 0)
			continue;

		calculateAndPrintResult(date, value, rate);
	}
	file.close();
}

int BitcoinExchange::validateInputLine(std::string date, std::string value_text)
{
	int i = 0;
	if (date.length() != 10)
		return (0);
	if (date[4] != '-' || date[7] != '-')
		return (0);
	while (i < 10)
	{
		if (i == 4 || i == 7)
		{
			i++;
			continue;
		}
		if (!isdigit(date[i]))
			return (0);
		i++;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (0);
	if (day < 1 || day > 31)
		return (0);
	if (year < 1000 || year > 2030)
		return (0);
	float v = std::atof(value_text.c_str());
	if (v < 0 || v > 1000)
		return 0;
	return (1);
}
float BitcoinExchange::getBitcoinRate(const std::string &date)
{
	std::map<std::string, float>::iterator it = values.find(date);
	std::map<std::string, float>::iterator it_map = values.begin();
	float ret = 0;
	int f = 0;

	if (it != values.end())
		return (it->second);
	while (it_map != values.end())
	{
		if (it_map->first <= date)
		{
			ret = it_map->second;
			f = 1;
		}
		else
			break;
		++it_map;
	}
	if (f == 0)
	{
		std::cout << "Error: no available rate for this date => " << date << std::endl;
		return (-1);
	}
	return (ret);
}

void BitcoinExchange::calculateAndPrintResult(std::string date, float value, float rate)
{
	std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}
