#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if(this != &other)
		*this = other;
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::loadDatabase(const char *filename)
{
	std::ifstream file;
	std::string date;
	std::string line;

	file.open(filename);
	if(!file)
	{
		std::cerr<< "Can't open input file!" << std::endl;
		return(0);
	}
	std::getline(file, line);
	while(std::getline(file, line))
	{
		
	}
	file.close();
}




