#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include "Intern.hpp"


int	main(void)
{
	Intern someIntern;
	AForm* form;
	Bureaucrat bc("Kinga", 1);
	form = someIntern.makeForm("robotomy request", "Bender");
	if(form)
	{
		form->beSigned(bc);
		form->checkForm(bc);
	}
	delete(form);
	AForm* form1 = someIntern.makeForm("presidential pardon", "Loki");
	if(form1)
	{
		form1->beSigned(bc);
		form1->checkForm(bc);
		delete(form1);
	}
	AForm* form2 = someIntern.makeForm("shrubbery creation", "Bebok");
	if(form2)
	{
		form2->beSigned(bc);
		form2->checkForm(bc);
		delete(form2);
	}
	return(0);
}
