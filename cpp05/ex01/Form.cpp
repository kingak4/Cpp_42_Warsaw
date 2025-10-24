#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if(signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
	this->isSigned = other.isSigned;
}

Form& Form::operator=(Form &other)
{
	if(this == &other)
		return(*this);
	this->isSigned = other.isSigned;
	return(*this);
}

Form::~Form(){}

bool Form::getIsSigned(void) const
{
	return(isSigned);
}

int Form::getSignGrade(void) const
{
	return(signGrade);
}

int Form::getExecGrade(void) const
{
	return(execGrade);
}

std::string	Form::getName(void) const
{
	return(name);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade is too low");
}
