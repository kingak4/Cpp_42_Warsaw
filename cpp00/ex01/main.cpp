#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

int main()
{
	std:: string cmd;
	std::cout << "Welcome to Phone Book !";
	std::cout << "Commands: ADD, SEARCH, EXIT"; // add this to loop
	std::cout << std::endl;
	while(true)
	{
		std:: cin >> cmd;
		if (cmd == "ADD")
		{

		}
		else if (cmd == "SEARCH")
		{

		}
		else if (cmd == "EXIT")
		{
			std::cout << "Exiting the Phone Book";
			return(0);
		}
		else
		{
			std::cout << "Unknown command. Please try again." << std::endl;
			std::cout << "Commands: ADD, SEARCH, EXIT";
		}
	}
	return(0);
}