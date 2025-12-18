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
int checker_a(char *s);
			int	checker_s(std::string s);
			int is_char(char *s);
			int check_nb(char *s);
			int checker_int(char *s);
			int make_int(char *s,int *out);
			int only_one(char *s);
			int is_flo(char *s);
			int final(char *s);
			int print_int(char *s);

#endif