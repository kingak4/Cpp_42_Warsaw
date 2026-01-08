/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:17:46 by kikwasni          #+#    #+#             */
/*   Updated: 2026/01/08 17:17:50 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		int validateInputLine(std::string date,std::string value_text);
		float getBitcoinRate(const std::string& date);
		void calculateAndPrintResult(std::string date, float value, float rate);
		void processInputFile(const char *filename);
};

#endif