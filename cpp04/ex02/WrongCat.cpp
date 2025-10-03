#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout<< "WrongCat constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	return(*this);
}

WrongCat:: ~WrongCat()
{
	std::cout<< "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << " WrongCat rawr rawr" << std::endl;
}