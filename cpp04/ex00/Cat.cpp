#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout<< "Cat constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Cat Copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return(*this);
}

Cat:: ~Cat()
{
	std::cout<< "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
