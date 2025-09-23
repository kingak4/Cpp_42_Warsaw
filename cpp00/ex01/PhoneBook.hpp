
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <cstdlib>

#ifndef PHONEBOOK_CLASS_CPP
# define PHONEBOOK_CLASS_CPP

class Contact
{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	int phoneNumber;
	std::string secret;

	public:
		int add_first(std::string s);
		int add_last(std::string s);
		int add_nick(std::string s);
		int add_number(std::string s);
		int add_secret(std::string s);
		void add_contact();
		std::string truncate_s(std::string s);
		void display_one_line(int id);
		bool isEmpty();
		
};
class PhoneBook
{
	private:
	Contact contacts[8];
	int	curr_id;
	public:
	PhoneBook() : curr_id(0) {} 
    void add_C(); 
	void display_tab(); 
};

#endif