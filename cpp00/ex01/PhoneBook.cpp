#include "PhoneBook.hpp"

int isnb(std::string s)
{
	for (size_t i = 0; i < s.length(); ++i)
	{
    	char c = s[i];
    	if (!isdigit(c))
        	return 0;
	}
	return(1);
}

int Contact::add_first(std::string s)
{
	if(!s.empty())
		this->firstName = s;
	else
	{
		std::cout << "First name cannot be empty. Please try again.." << std::endl;
		return(0);
	}
	return(1);
}
int Contact::add_last(std::string s)
{
	if(!s.empty())
		this->lastName = s;
	else
	{
		std::cout << "Last name cannot be empty. Please try again.." << std::endl;
		return(0);
	}
	return(1);
}

int Contact::add_nick(std::string s)
{
	if(!s.empty())
		this->nickname = s;
	else
	{
		std::cout << "Nick name cannot be empty. Please try again.." << std::endl;
		return(0);
	}
	return(1);
}

int Contact::add_number(std::string s)
{
	if(!s.empty())
	{
		if(!isnb(s))
		{
			std::cout << "Phone number must be numeric!" << std::endl;
		}
		this->phoneNumber = atoi(s.c_str());
	}
	else
	{
		std::cout << "Phone number cannot be empty. Please try again.." << std::endl;
		return(0);
	}
	return(1);
}
int Contact::add_secret(std::string s)
{
	if(!s.empty())
		this->secret = s;
	else
	{
		std::cout << "Darkest secret  cannot be empty. Please try again.." << std::endl;
		return(0);
	}
	return(1);
}

void Contact::add_contact()
{
	std::string s;
	while(true)
	{
		std::cout << "Enter first name:";
		std::getline(std::cin,s);
		if(add_first(s))
			break;
	}
	while(true)
	{
		std::cout << "Enter last name:";
		std::getline(std::cin,s);
		if(add_last(s))
			break;
	}
	while(true)
	{
		std::cout << "Enter nickname:";
		std::getline(std::cin,s);
		if(add_nick(s))
			break;
	}
	while(true)
	{
		std::cout << "Enter phone number:";
		std::getline(std::cin,s);
		if(add_number(s))
			break;
	}
	while(true)
	{
		std::cout << "Enter darkest secret:";
		std::getline(std::cin,s);
		if(add_secret(s))
			break;
	}
}

void PhoneBook::add_C()
{
	Contact	new_phone;

	new_phone.add_contact();
	contacts[curr_id] = new_phone;
	curr_id++;
	if (curr_id >= 8)
		curr_id = 0;
	std::cout << "Contact added successfully!" << std::endl;
}
std::string Contact::truncate_s(std::string s)
{
	int i = 0;
	std::string rest;
	if(s.length() <= 10)
		return(s);
	else
	{
		while(i < 9)
		{
			rest += s[i];
			i++;
		}
		rest += '.';
		return(rest);
	}
}
void	Contact::display_one_line(int id)
{
	if(this->firstName.empty())
		return ;
	else
	{
		std::cout << id;
		std::cout << "|";
		std::cout << truncate_s(this->firstName);
		std::cout << "|";
		std::cout << truncate_s(this->lastName);
		std::cout << "|";
		std::cout << truncate_s(this->nickname);
	}
}
bool Contact::isEmpty() { return firstName.empty(); }

void PhoneBook::display_tab()
{
	std::cout << "     Index|First Name| Last Name|  Nickname " << std::endl;
	int i = 0;
	int id = 0;
	while( i < 8)
	{
		if(!contacts[i].isEmpty())
		{
			contacts[i].display_one_line(i + 1);
			id = 1;
		}
		i++;
	}
	if (id == 0)
		std::cout << "No contacts in the phone book." << std::endl;
}