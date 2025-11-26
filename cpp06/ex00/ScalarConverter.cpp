#include "ScalarConverter.hpp"

std::string trim(char *s)
{
	if(!s)
		return(NULL);
	int start = 0;
	int end = 0;
	int len = 0;
	int i = 0;

	while(s[end])
		end++;
	if (end == 0)
		return(NULL);
	end -= 1;
	while(s[end] == 32)
		end--;
	while(s[start] == 32)
		start++;
	if (start > end)
		return(NULL);
	len = end - start + 1;
	std::string st(len, ' ');
	while(i < len)
	{
		st[i] = s[start + i];
		i++;
	}
	return(st);
}
