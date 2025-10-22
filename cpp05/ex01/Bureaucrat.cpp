#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Inputname, int Inputgrade) : name(Inputname)
{

	if(Inputgrade < 1)
		throw GradeTooHighException();
	else if (Inputgrade > 150)
		throw GradeTooLowException();
	else
		this->grade = Inputgrade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : name(other.name)
{
	this->grade  = other.grade;
	std::cout << "Bureaucrat " << name << " copied" <<std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	if(this == &other)
		return(*this);
	this->grade = other.grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " destroyed" <<std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return(name);
}
int	Bureaucrat::getGrade(void) const
{
	return(grade);
}

void Bureaucrat::incrementGrade()
{
	if(grade == 1)
		throw GradeTooHighException();
	else
		grade = grade - 1;
}
void Bureaucrat::decrementGrade()
{
	if(grade == 150)
		throw GradeTooLowException();
	else
		grade = grade + 1;
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}
void Bureaucrat::signForm(Form &f) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << "Couldn't sign " << form.getName() << " because " << getName() << "'s grade is too low!" << std::endl;
	}	
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out<< b.getName() << ", bureaucrat grade " << b.getGrade() <<std::endl;
	return(out);
}
