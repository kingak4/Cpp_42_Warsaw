#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72 , 45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72 , 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other), target(other.getTarget()){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	(void)other;
	return(*this);
}
RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget(void) const
{
	return(target);
}

void RobotomyRequestForm::checkForm(Bureaucrat const &executor) const
{
	try
	{
		AForm::checkForm(executor);
		std::cout << "BZZZZ... drilling noises..." << std::endl;
		int number = rand() % 2;
		std::string msg;
		if (number == 1)
			msg = "succeeded!";
		else
			msg = "failed!";
		std::cout << getTarget() << " robotomy " << msg <<std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}