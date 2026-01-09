#include "RPN.hpp"

int main(int ac, char *av[])
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Error");
		RPN r;
		int rr = r.execute(av[1]);
		std::cout << rr << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}