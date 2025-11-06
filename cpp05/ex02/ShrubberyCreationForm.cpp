#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target){}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm(other), target(other.getTarget()){}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkForm(executor);
		std::string fileName = getTarget() + "_shrubbery";
		std::ofstream shrubberyFile(fileName.c_str());
		shrubberyFile << "  *      *" << std::endl;
		shrubberyFile << " * *    * *" << std::endl;
		shrubberyFile << "*   *  *   *" << std::endl;
		shrubberyFile << " | |    | |" << std::endl;
		shrubberyFile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<  std::endl;;
	}
}

