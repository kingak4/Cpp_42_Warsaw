#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <cerrno>

class ScalarConverter {
	public:
			static void convert(std::string const & literal);
	private:
			ScalarConverter();
			ScalarConverter(ScalarConverter const&);
			ScalarConverter& operator=(ScalarConverter const&);
			~ScalarConverter();
};

#endif