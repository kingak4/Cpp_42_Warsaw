#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of the argumets. Try again"<<std::endl;
		return(1);
	}
	if (std::string(av[2]).empty())
	{
		std::cout << "Empty search string!" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream input(filename.c_str());
	int found = 0;
	if(!input.is_open())
	{
		std::cout << "Can't open file!" << std::endl;
		return(1); 
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream output(outputFilename.c_str());
	if(!output.is_open())
	{
		std::cout << "Can't create output file!" << std::endl;
		return(1);
	}
	std::string line;
	while(getline(input, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos,s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
			found = 1;
		}
		output << line << std::endl;
		
	}
	if (!found)
	{
		std::cout << "String \"" << s1 << "\" was not found in the file." << std::endl;
		return(1);
	}
	input.close();
	output.close();
	return(0);
}