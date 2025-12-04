#include "ScalarConverter.hpp"

// checker for spaces 
int checker_a(char *s)
{
	if(!s)
		return(0);
	while(*s)
	{
		if(isspace(*s))
			return(0);
		s++;
	}
	return(1);
}

int	checker_s(std::string s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff")
		return(1);
	return(0);
}

int is_char(char *s)
{
	int len = 0;
	int i = 0;
	while(s[len])
		len++;
	if (len == 1)
		return(1);
	if(len == 3)
	{
		if (s[i] == '\'')
		{
			i += 2;
			if (s[i] == '\'')
				return(2);
			else
				return (0);
		}
		else
			return(0);
	}
	return(0);
}

// check for only numbers, char f or .
int check_nb(char *s)
{
	int i = 0;

	if(s[i] == '-' || s[i]  == "+")
		i++;
	while (s[i])
	{
		if(!isdigit(s[i]))
		{
			if(s[i] != '.' && s[i] != 'f')
				return(0);
		}
		i++;
	}
	return(1);
}


// chceker if we have matching '1' or is only one 0
// and this example 02828

int checker_int(char *s)
{
	int i = 0;
	int len = 0;

	while(s[len])
		len++;
	if (s[i] == '0' && len == 1)
		return(1);
	if(len == 3)
	{
		if (s[i] == '\'')
		{
			i += 2;
			if (s[i] == '\'')
				return(1);
			else
				return (0);
		}
		else
			return(0);
	}
	if (len >= 4)
	{
		if(s[i] == '0')
			return(0);
	}
	return(1);
}

int make_int(char *s,int *out)
{
	char *endptr;
	errno = 0;
	long val = strtol(s, &endptr, 10);
	if (*endptr != '\0') 
		return(0);
	if (errno == ERANGE)
		return(0);
	if (val < INT_MIN || val > INT_MAX)
		return(0);
	*out = (int)val;
	return(1);
}

// chekcs ++ -- +- and + or - shoud be fisrt
// checks two .. and  more than one f char

int only_one(char *s)
{
	int plus = 0;
	int minus = 0;
	int dot = 0;
	int flag = 0;
	int where = -1;
	int w = -1;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '+')
		{
			plus++;
			where = i;
		}
		else if (s[i] == '-')
		{
			minus++;
			w = i;
		}
		else if(s[i] == 'f')
			flag++;
		else if (s[i] == '.')
			dot++;
		i++;
	}
	if ((where != -1 && where != 0) || (w != -1 && w != 0))
		return (0);
	if(dot > 1 || flag > 1)
		return(0);
	if (minus >= 1 && plus >= 1)
		return(0);
	return(1); 
}


// check is f is last 
// if we have . in input 
// if we don't have f char this is double
int is_flo(char *s)
{
	int i = 0;
	int flag = 0;
	int f = 0;

	while(s[i])
	{
		if(s[i] == '.')
			flag = 1;
		if(s[i] == 'f')
			f = 1;
		if(s[i] == 'f' && s[i + 1] != '\0')
			return(0); 
		i++;
	}
	if (flag == 0)
		return(0);
	if(f != 1)
		return(2);
	return(1);
}

int final(char *s)
{
	if(checker_a(s) == 0)
	{
		std::cout << "Input can't have any spaces" << std::endl;
		return(0);
	}
	std::string str = s;
	if(checker_s(str) == 1)
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		if( str == "nanf"|| str == "+inff" || str == "-inff")
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
	if(is_char(s) == 1)
	{
		if(isprint(*s))
			std::cout << "char: " <<"'"<< s <<"'" << std::endl;
		else
			std::cout << "char: Non displayable"<< std::endl;
		std::cout << "int: " << (int)*s << std::endl;
		std::cout << "float: " << (float)*s << ".0f" <<std::endl;
		std::cout << "double: " << (double)*s << ".0" <<std::endl;
	}
	else if (is_char(s) == 2)
	{
		char c = s[1];
		if(isprint(c))
			std::cout << "char: " << s << std::endl;
		else
			std::cout << "char: Non displayable"<< std::endl;
		std::cout << "int: " << (int)c << std::endl;
		std::cout << "float: " << (float)c << ".0f" <<std::endl;
		std::cout << "double: " << (double)c << ".0" <<std::endl;
	}
}

int print_int(char *s)
{
	int value = 0;
	char c = 0;
	int len = 0;
	if(check_nb(s) == 0 || only_one(s) == 0 || checker_int(s) == 0)
	{
		std::cout << "Wrong format" << std::endl;
		return(0);
	}
	if (make_int(s, &value))
	{
		c = (char)value;
		if (isprint(c))
		{
			std::cout << "char: " <<"'"<< c <<"'" << std::endl;
			std::cout << "Int: " << value << std::endl;
			std::cout << "float: " << (float)c << ".0f" <<std::endl;
			std::cout << "double: " << (double)c << ".0" <<std::endl;
		}
		else
		{
			std::cout << "char: impossible"<< std::endl;
			std::cout << "Int: " << value << std::endl;
			std::cout << "float: " << (float)c << ".0f" <<std::endl;
			std::cout << "double: " << (double)c << ".0" <<std::endl;
		}
	}
	return(1);
}

int print_float_and_double(char *s)
{
	if(check_nb(s) == 0 || only_one(s) == 0 || is_flo(s) == 0)
	{
		std::cout << "Wrong format" << std::endl;
		return(0);
	}
	if(is_flo(s) == 1)
	{

	}
	else if (is_flo(s) == 2)
}