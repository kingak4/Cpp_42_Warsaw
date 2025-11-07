#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
			const std::string name;
			bool isSigned;
			const int signGrade;
			const int execGrade;
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm &other);
		AForm &operator=(AForm &other);
		virtual ~AForm();
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		std::string	getName(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		friend std::ostream& operator<<(std::ostream& out, const AForm& f);
		virtual void checkForm(Bureaucrat const &executor) const = 0;

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
		class FormNotSignedException : public  std::exception
		{
			public :
				const char* what() const throw();
		};
};


#endif