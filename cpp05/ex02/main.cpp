#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>


int	main(void)
{
	Bureaucrat bc("Bob", 1);
	Bureaucrat bcc("Bobby", 150);
	ShrubberyCreationForm scf("tree");
	RobotomyRequestForm rrf("Robot");
	PresidentialPardonForm ppf("Kinny");

	try
	{
		scf.checkForm(bc);
	}
	catch(const AForm::FormNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bc.signForm(scf);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		scf.checkForm(bc);
	}
	catch(const AForm::FormNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		scf.checkForm(bcc);
	}
	catch(const AForm::FormNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bcc.signForm(scf);
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		scf.checkForm(bcc);
	}
	catch(const AForm::FormNotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	bc.signForm(scf);
	bc.signForm(rrf);
	bc.signForm(ppf);
	scf.checkForm(bc);
	rrf.checkForm(bc);
	ppf.checkForm(bc);
}