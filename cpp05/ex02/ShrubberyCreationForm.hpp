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
			void execute(Bureaucrat const &executor) const;

}

#endif