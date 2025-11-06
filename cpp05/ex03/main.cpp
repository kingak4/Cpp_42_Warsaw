#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include "Intern.hpp"


int	main(void)
{
	Intern someIntern;
	AForm* form;
	form = someIntern.makeForm("robotomy request", "Bender");

}
//  form = someIntern.makeForm("robotomy request", "Bender");

//    if (form)
//        std::cout << "Form created successfully!" << std::endl;
//    else
//        std::cout << "Form creation failed." << std::endl;

//    delete form; // jeśli nie NULL, zwolnij pamięć
//    return 0;
//2. Zadeklaruj wskaźnik na AForm (bo makeForm zwraca AForm*)
//   → AForm* form;

//3. Wywołaj makeForm dla każdego typu formularza:

//   a) form = someIntern.makeForm("robotomy request", "Bender")
//      → Intern wypisze, że tworzy form robotomy request
//      → makeForm zwróci wskaźnik do nowego RobotomyRequestForm
//      → wypisz nazwę formularza i target, żeby potwierdzić

//   b) form = someIntern.makeForm("shrubbery creation", "home")
//      → Intern wypisze, że tworzy shrubbery creation
//      → sprawdź, że wskaźnik nie jest NULL
//      → usuń obiekt po użyciu (delete form)

//   c) form = someIntern.makeForm("presidential pardon", "Alice")
//      → Intern wypisze, że tworzy presidential pardon
//      → ewentualnie wykonaj form.execute(bureaucrat) dla testu

//4. Przetestuj błędny przypadek:
//   → form = someIntern.makeForm("wrong form name", "nobody")
//   → Intern wypisze "Wrong Form !"
//   → upewnij się, że zwrócił NULL

//5. Na końcu:
//   → usuń wszystkie zaalokowane formularze (jeśli jakieś istnieją)
//   → zakończ program.
}