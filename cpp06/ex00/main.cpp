#include "ScalarConverter.hpp"
#include <string>
#include <iostream>


int main(int ac, char *av[])
{
	if(ac > 2)
		return(0);
	ScalarConverter::convert(av[1]);

}