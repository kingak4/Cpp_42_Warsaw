#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");
	ClapTrap jake("Jake");
	bob.attack(jake.getName());
	bob.takeDamage(1);
	bob.beRepaired(3);
	jake.takeDamage(10);
	return(0);
}
