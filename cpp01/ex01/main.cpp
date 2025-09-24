#include "Zombie.hpp"

int main()
{
	Zombie* z = zombieHorde(5, "BOB");
	delete [] z;
	return(0);
}
