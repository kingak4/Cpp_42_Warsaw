#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout<< "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if(this == &other)
		return(*this);
	this->type = other.type;
	return(*this);
}

WrongAnimal:: ~WrongAnimal()
{
	std::cout<< "WrongAnimal destructor called" << std::endl;
}
std::string WrongAnimal::getType() const
{
	return(type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal makes a loud sound" << std::endl;
}
