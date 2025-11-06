#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
			const std::string name;
			int grade;
	public:
		Bureaucrat(std::string Inputname, int Inputgrade);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		~Bureaucrat();
		std::string	getName(void) const;
		int	getGrade(void) const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &f) const;
		friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public  std::exception
		{
			public :
				const char* what() const throw();
		};
};


#endif