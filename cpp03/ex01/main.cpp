#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ct("Ed");
	ScavTrap st("Eddy");

	st.guardGate();
	st.attack(ct.getName());
	ct.takeDamage(20);
	st.beRepaired(3);
	st.takeDamage(20);
}
