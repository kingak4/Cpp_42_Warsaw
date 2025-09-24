#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
	public:
			Zombie();
			~Zombie();
			void announce();
			void set_Zombie(std::string name);
	private:
			std::string name;

};
Zombie* zombieHorde(int N, std::string name);

#endif