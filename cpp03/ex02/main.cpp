#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap ct("Ed");
	ScavTrap st("Eddy");
	FragTrap ft("Edward");

	st.guardGate();
	st.attack(ct.getName());
	ct.takeDamage(20);
	st.beRepaired(3);
	ft.highFivesGuys();
}