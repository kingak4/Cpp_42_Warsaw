#include "Animal.hpp"

Animal::Animal()
{
	std::cout<< "Animal constructor called" << std::endl;
}
Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "Animal Copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal &other)
{
	if(this == &other)
		return(*this);
	this->type = other.type;
	return(*this);
}

Animal:: ~Animal()
{
	std::cout<< "Animal destructor called" << std::endl;
}
std::string Animal::getType() const
{
	return(type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal makes a generic sound" << std::endl;
}
