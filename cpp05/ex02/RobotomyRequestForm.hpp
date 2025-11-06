#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
	private:
			const std::string target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(RobotomyRequestForm &other);
			RobotomyRequestForm &operator=(RobotomyRequestForm &other);
			~RobotomyRequestForm();
			std::string getTarget(void) const;
			void checkForm(Bureaucrat const &executor) const;
};

#endif