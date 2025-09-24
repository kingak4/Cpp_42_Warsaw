#include "Zombie.hpp"

int main() 
{
    randomChump("Bartek");
    Zombie* z = newZombie("Kinga");
	z->announce();
	delete(z);
    return (0);
}

