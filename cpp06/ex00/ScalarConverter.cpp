#include "ScalarConverter.hpp"


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
	else
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
				return(1);
			else
				return (0);
		}
		else
			return(0);
	}
	return(0);
}

int is_nb(char *s)
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
	if(s[i] == '-' || s[i]  == "+")
		i++;
	while (s[i])
	{
		if(!isdigit(s[i]))
			return(0);
		i++;
	}
	char *endptr;
	errno = 0;
	long val = strtol(s, &endptr, 10);
	if (*endptr != '\0') 
		return(0);
	if (errno == ERANGE)
		return(0);
	if (val < INT_MIN || val > INT_MAX)
		return(0);
	int v = val;
	return(v);
}
