#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout<< "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Dog Copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return(*this);
}

Dog:: ~Dog()
{
	std::cout<< "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}
