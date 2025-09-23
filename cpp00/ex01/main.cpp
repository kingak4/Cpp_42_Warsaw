#include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>

int main()
{
	std:: string cmd;
	PhoneBook myPhoneBook;
	std::cout << "Welcome to Phone Book !";
	// std::cout << "Commands: ADD, SEARCH, EXIT"; // add this to loop
	std::cout << std::endl;
	while(true)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT";
		std::cout << std::endl;
		std::cout << "Enter command : ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			myPhoneBook.add_C();
		}
		else if (cmd == "SEARCH")
		{
			myPhoneBook.showContactDetails();
		}
		else if (cmd == "EXIT")
		{
			std::cout << "Exiting the Phone Book";
			std::cout << std::endl;
			return(0);
		}
		else
		{
			std::cout << "Unknown command. Please try again." << std::endl;
		}
	}
	return(0);
}