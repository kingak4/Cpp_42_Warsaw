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

int BitcoinExchange::readInputFile(const char *filename)
{
	std::ifstream file;
	std::string line;
	std::string date;
	std::string rate_text;

	file.open(filename);
	if (!file)
	{
		std::cerr << "Can't open input file!" << std::endl;
		return (0);
	}
	std::getline(file, line);
	while (getline(file, line))
	{
		size_t r = line.find(" | ");
		if (r == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, r);
		rate_text = line.substr(r + 3);
		std::cout << "data = " << data << " | value = " << rate_text << std::endl;
	}
	file.close();
	return (1);
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

	if(month < 1 || month > 12)
		return(0);
	if(day < 1 || day > 31)
		return(0);
	if(year < 1000 || year > 2030)
		return(0);
	float v = std::atof(value_text.c_str());
	if(v < 0 || v > 1000)
		return(0);
	return (1);
}
