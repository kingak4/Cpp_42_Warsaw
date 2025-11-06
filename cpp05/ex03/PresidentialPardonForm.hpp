#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			const std::string target;
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(PresidentialPardonForm &other);
			PresidentialPardonForm &operator=(PresidentialPardonForm &other);
			~PresidentialPardonForm();
			std::string getTarget(void) const;
			void checkForm(Bureaucrat const &executor) const;
};

#endif