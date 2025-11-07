#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(Intern &other){(void)other;}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return(*this);
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;

	while(i < 3)
	{
		if (formName == formNames[i])
		{
			if (i == 0)
			{
				std::cout << "Intern creates form presidential pardon" << std::endl;
				return(new PresidentialPardonForm(target));
			}
			else if (i == 1)
			{
				std::cout << "Intern creates form robotomy request" << std::endl;
				return(new RobotomyRequestForm(target));
			}
			else if (i == 2)
			{
				std::cout << "Intern creates form shrubbery creation" << std::endl;
				return(new ShrubberyCreationForm(target));
			}
		}
		i++;
	}
	std::cout << "Wrong Form !" << std::endl;
	return(NULL);
}
