#include "ScalarConverter.hpp"

std::string trim(char *s)
{
	if(!s)
		return(NULL);
	int start = 0;
	int end = 0;
	int c = 0;
	int sc = 0;
	std:: string st;

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
	c = end - start + 1;
	sc = start;
	std:: string st = c;
	while(sc <= end)
	{
		st[sc] = s[sc];
	}
}
