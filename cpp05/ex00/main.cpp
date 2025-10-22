#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main()
{
	Bureaucrat bc("Bob", 5);
	Bureaucrat *bc2 = new Bureaucrat(bc);
	bc.incrementGrade();
	bc2->decrementGrade();
	std::cout << bc;
	std::cout << *bc2 << std::endl;
	delete(bc2);
	try
	{
		Bureaucrat bc3("Bobik", 7);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat bc4("Daniel", 60);
		bc4.incrementGrade();
		std::cout << bc4;
		bc4.decrementGrade();
		std::cout << bc4;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat bc4("Kate", 0);
		bc4.incrementGrade();
		std::cout << bc4;
		bc4.decrementGrade();
		std::cout << bc4;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat bc4("Carol", 150);
		bc4.incrementGrade();
		std::cout << bc4;
		bc4.decrementGrade();
		std::cout << bc4;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
		try
	{
		Bureaucrat bc4("Kinga", 155);
		bc4.incrementGrade();
		std::cout << bc4;
		bc4.decrementGrade();
		std::cout << bc4;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return(0);
}

