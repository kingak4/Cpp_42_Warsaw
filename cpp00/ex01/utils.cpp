#include "PhoneBook.hpp"
std::string Contact::truncate_s(std::string s)
{
	int i = 0;
	std::string rest;
	if (s.length() <= 10)
		return (s);
	else
	{
		while (i < 9)
		{
			rest += s[i];
			i++;
		}
		rest += '.';
		return (rest);
	}
}
void Contact::display_one_line(int id)
{
	if (this->firstName.empty())
		return;
	else
	{
		std::cout << std::right << std::setw(10) << id << "|"
				  << std::right << std::setw(10) << truncate_s(firstName) << "|"
				  << std::right << std::setw(10) << truncate_s(lastName) << "|"
				  << std::right << std::setw(10) << truncate_s(nickname) << std::endl;
	}
}
bool Contact::isEmpty() { return firstName.empty(); }

void PhoneBook::display_tab()
{
	std::cout << "     Index|First Name| Last Name|  Nickname " << std::endl;
	int i = 0;
	int id = 0;
	while (i < 8)
	{
		if (!contacts[i].isEmpty())
		{
			contacts[i].display_one_line(i + 1);
			id = 1;
		}
		i++;
	}
	if (id == 0)
		std::cout << "No contacts in the phone book." << std::endl;
}
void Contact::display_full()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}
int PhoneBook::getContactCount()
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
			count++;
	}
	return count;
}
int PhoneBook::showContactDetails()
{
	int totalContacts = getContactCount();
	std::string s;
	if (totalContacts == 0)
	{
		std::cout << "No cotacts in Phone Book. Please add one." << std::endl;
		return (0);
	}
	display_tab();
	std::cout << "Enter contact index to display (1-" << totalContacts << "): ";
	std::getline(std::cin, s);
	if (s.empty())
	{
		std::cout << "No input provided. Please enter a valid index." << std::endl;
		;
		return (0);
	}
	if (!isnb(s))
	{
		std::cout << "Index must be a numeric value.  Please enter a valid index." << std::endl;
		;
		return (0);
	}
	int index = atoi(s.c_str());
	if (index < 1 || index > totalContacts)
	{
		std::cout << "Index out of range. Please enter a valid index." << std::endl;
		;
		return (0);
	}
	int current = 0;
	int arrayIndex = -1;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			continue;
		current++;
		if (current == index)
		{
			arrayIndex = i;
			break;
		}
	}
	contacts[arrayIndex].display_full();
	return (1);
}
