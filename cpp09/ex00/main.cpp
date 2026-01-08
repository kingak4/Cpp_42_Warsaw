#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange bc;
	bc.loadDatabase("data.csv");
	bc.readInputFile(av[1]);
	return (0);
}
