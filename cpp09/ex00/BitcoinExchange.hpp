#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> values;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		int loadDatabase(const char *filename);
		int readInputFile(const char *filename);
		int validateInputLine(std::string date,std::string value_text);
		float getBitcoinRate(const std::string& date);
		void calculateAndPrintResult(std::string date, float value, float rate);
};

#endif