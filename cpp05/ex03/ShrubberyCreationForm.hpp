#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
			const std::string target;
	public :
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(ShrubberyCreationForm &other);
			ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
			~ShrubberyCreationForm();
			std::string getTarget(void) const;
			void checkForm(Bureaucrat const &executor) const;

};

#endif