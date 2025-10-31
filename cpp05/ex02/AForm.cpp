#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if(signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(Form &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
	this->isSigned = other.isSigned;
}

AForm& AForm::operator=(Form &other)
{
	if(this == &other)
		return(*this);
	this->isSigned = other.isSigned;
	return(*this);
}

AForm::~AForm(){}

bool AForm::getIsSigned(void) const
{
	return(isSigned);
}

int AForm::getSignGrade(void) const
{
	return(signGrade);
}

int AForm::getExecGrade(void) const
{
	return(execGrade);
}

std::string	AForm::getName(void) const
{
	return(name);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= signGrade)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() << ", isSigned: " << f.getIsSigned() << ", signGrade: " << f.getSignGrade() << ", execGrade: " << f.getExecGrade() << std::endl;
	return(out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade is too low");
}
