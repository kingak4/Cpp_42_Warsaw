#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

// checker for spaces
int checker_spaces(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

int checker_string(std::string s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		return (1);
	return (0);
}

int is_char(const char *s)
{
	int len = 0;
	int i = 0;
	while (s[len])
		len++;
	if (len == 1)
		return (1);
	if (len == 3)
	{
		if (s[i] == '\'')
		{
			i += 2;
			if (s[i] == '\'')
				return (2);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}

int is_float(const char *s)
{
	int i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!isdigit(s[i]))
		{
			if (s[i] != '.' && s[i] != 'f')
				return (0);
		}
		i++;
	}
	return (1);
}

// chceker if we have matching '1' or is only one 0
// and this example 02828

int checker_int(const char *s)
{
	int i = 0;
	int len = 0;

	while (s[len])
		len++;
	if (s[i] == '0' && len == 1)
		return (1);
	if (len == 3)
	{
		if (s[i] == '\'')
		{
			i += 2;
			if (s[i] == '\'')
				return (1);
			else
				return (0);
		}
		else
			return (0);
	}
	if (len >= 4)
	{
		if (s[i] == '0')
			return (0);
	}
	return (1);
}

int make_int(const char *s, int *out)
{
	char *endptr;
	errno = 0;
	long val = strtol(s, &endptr, 10);
	if (*endptr != '\0')
		return (0);
	if (errno == ERANGE)
		return (0);
	if (val < -2147483648L || val > 2147483647L)
		return (0);
	*out = (int)val;
	return (1);
}

int count_char(const char *s, char c)
{
	int i = 0;
	int count = 0;

	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
int sign_is_valid(const char *s)
{
	int i = 0;

	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && i != 0)
			return (0);
		i++;
	}
	return (1);
}
int dot_is_valid(const char *s)
{
	if (count_char(s, '.') > 1)
		return (0);
	return (1);
}
int f_is_valid(const char *s)
{
	if (count_char(s, 'f') > 1)
		return (0);
	return (1);
}
int sign_conflict(const char *s)
{
	if (count_char(s, '+') > 0 && count_char(s, '-') > 0)
		return (0);
	return (1);
}
// check is f is last
// if we have . in input
// if we don't have f char this is double
int flo_checker(const char *s)
{
	int i = 0;
	int flag = 0;
	int f = 0;

	while (s[i])
	{
		if (s[i] == '.')
			flag = 1;
		if (s[i] == 'f')
			f = 1;
		if (s[i] == 'f' && s[i + 1] != '\0')
			return (0);
		i++;
	}
	if (flag == 0)
		return (0);
	if (f != 1)
		return (2);
	return (1);
}

int print_char(const char *s)
{
	std::string str = s;
	if (checker_string(str) == 1)
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		if (str == "nanf" || str == "+inff" || str == "-inff")
		{
			std::cout << "float: " << str << std::endl;
			str.erase(str.size() - 1, 1);
			std::cout << "double: " << str << std::endl;
		}
		else
		{
			std::cout << "double: " << str << std::endl;
			std::cout << "float: " << str << "f" << std::endl;
		}
	}
	if (is_char(s) == 1)
	{
		if (isprint(*s))
			std::cout << "char: " << "'" << s << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << (int)*s << std::endl;
		std::cout << "float: " << (float)*s << ".0f" << std::endl;
		std::cout << "double: " << (double)*s << ".0" << std::endl;
	}
	else if (is_char(s) == 2)
	{
		char c = s[1];
		if (isprint(c))
			std::cout << "char: " << s << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << (int)c << std::endl;
		std::cout << "float: " << (float)c << ".0f" << std::endl;
		std::cout << "double: " << (double)c << ".0" << std::endl;
	}
	return (1);
}

int print_int(const char *s)
{
	int value = 0;
	char c = 0;
	if (make_int(s, &value))
	{
		c = (char)value;
		if (isprint(c))
		{
			std::cout << "char: " << "'" << c << "'" << std::endl;
			std::cout << "Int: " << value << std::endl;
			std::cout << "float: " << (float)value << ".0f" << std::endl;
			std::cout << "double: " << (double)value << ".0" << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "Int: " << value << std::endl;
			std::cout << "float: " << (float)value << ".0f" << std::endl;
			std::cout << "double: " << (double)value << ".0" << std::endl;
		}
	}
	return (1);
}
int print_float(const char *s)
{
	if (!checker_spaces(s) || !is_float(s) || !sign_is_valid(s) || !dot_is_valid(s) || !f_is_valid(s) || !flo_checker(s))
		return 0;
	std::string str = s;
	int len = str.size();
	if (str[len - 1] == 'f')
		str.erase(len - 1, 1);
	char *endptr;
	errno = 0;
	double val = strtod(str.c_str(), &endptr);
	if (*endptr != '\0' || errno == ERANGE)
	{
		std::cout << "Conversion error" << std::endl;
		return (0);
	}
	int i = static_cast<int>(val);
	float f = static_cast<float>(val);
	if (val >= 0 && val <= 127 && val == static_cast<int>(val))
	{
		char c = static_cast<char>(val);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (val >= -2147483648 && val <= 2147483648)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << val << ".0" << std::endl;
	return (1);
}
int print_dobule(const char *s)
{
	if (!checker_spaces(s) || !sign_is_valid(s) || !dot_is_valid(s))
		return 0;
	std::string str = s;
	char *endptr;
	errno = 0;
	double val = strtod(str.c_str(), &endptr);
	if (*endptr != '\0' || errno == ERANGE)
	{
		std::cout << "Conversion error" << std::endl;
		return (0);
	}
	int i = static_cast<int>(val);
	float f = static_cast<float>(val);
	if (val >= 0 && val <= 127 && val == static_cast<int>(val))
	{
		char c = static_cast<char>(val);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (val >= -2147483648 && val <= 2147483648)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << val << ".0" << std::endl;
	return (1);
}

void ScalarConverter::convert(std::string const &literal)
{
	if (!checker_spaces(literal.c_str()))
	{
		std::cout << "Input can't have any spaces" << std::endl;
		return;
	}
	if (checker_string(literal))
	{
		print_char(literal.c_str()); // obsłuży specjalne przypadki
		return;
	}
	if (is_char(literal.c_str()))
	{
		print_char(literal.c_str());
		return;
	}
	int int_val;
	if (make_int(literal.c_str(), &int_val))
	{
		print_int(literal.c_str());
		return;
	}
	int float_check = flo_checker(literal.c_str());
	if (is_float(literal.c_str()))
	{
		if (float_check == 1)
			print_float(literal.c_str());
		else if (float_check == 2)
			print_dobule(literal.c_str());
		return;
	}
	std::cout << "Unknown literal type" << std::endl;
}