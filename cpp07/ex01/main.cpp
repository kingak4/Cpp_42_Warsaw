#include "iter.hpp"

void print(int &i)
{
	std::cout << i;
}

void add_one(int &i)
{
	i += 1;
}

void to_upper(char &c)
{
	if(c >= 'a' && c<= 'z')
		c -= 32;
}

void to_lower(char &c)
{
	if(c >= 'A' && c<= 'Z')
		c += 32;
}

int main()
{
	char chars[] = {'a', 'b', 'c', 'D', 'E'};
	int ints[] = {1, 2, 3, 4, 5};
	int i = 0;

	iter(ints, 5, print);
	iter(ints, 5, add_one);
	std::cout<<std::endl;
	while(i < 5)
	{
		std::cout << ints[i];
		i++;
	}
	std::cout<<std::endl;
	i = 0;
	iter(chars, 5, to_upper);
	while(i < 5)
	{
		std::cout << chars[i];
		i++;
	}
	std::cout<<std::endl;
	iter(chars, 5, to_lower);
	i = 0;
	while(i < 5)
	{
		std::cout << chars[i];
		i++;
	}
	return(0);
}