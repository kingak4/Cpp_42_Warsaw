#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

int main()
{
	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Tom", 99);

	Form f1("TaxForm", 50, 30);
	Form f2("TopSecret", 1, 1);

	std::cout << f1;
	std::cout << f2 << std::endl;

	b1.signForm(f1);
	b2.signForm(f1);
	b2.signForm(f2);
	b1.signForm(f2);

	std::cout << f1;
	std::cout << f2 << std::endl;

	try
	{
		Form f3("InvalidForm", 0, 200);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
