#include "ScalarConverter.hpp"
#include <string>
#include <iostream>


int main(int ac, char *av[])
{
	if(ac == 2)
		ScalarConverter::convert(av[1]);
}