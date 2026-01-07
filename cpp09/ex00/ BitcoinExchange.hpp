#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <fstream>

class  BitcoinExchange
{
	private:
		float getValue(std::string date);
		std::map<std::string, float> values;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif