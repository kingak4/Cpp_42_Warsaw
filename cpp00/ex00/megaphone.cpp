#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	int j = 1;
	while(av[j])
	{
		int i = 0;
		while (av[j][i] != '\0')
		{
			char s = toupper(av[j][i]);
			std::cout << s;
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return(0);
}