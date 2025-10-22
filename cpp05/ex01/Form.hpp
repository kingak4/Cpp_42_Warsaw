#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
			const std::string name;
			bool isSigned;
			const int signGrade;
			const int execGrade;
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form &other);
		Form &operator=(Form &other);
		~Form();
		std::string	getName(void) const;
		bool getIsSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		friend std::ostream& operator<<(std::ostream& out, const Form& f);

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