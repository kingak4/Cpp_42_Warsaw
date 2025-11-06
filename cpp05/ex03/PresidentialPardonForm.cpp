#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25 , 5), target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25 , 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other), target(other.getTarget()){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	(void)other;
	return(*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget(void) const
{
	return(target);
}

void PresidentialPardonForm::checkForm(Bureaucrat const &executor) const
{
	try
	{
		AForm::checkForm(executor);
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}