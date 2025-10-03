#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout<< "Cat constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Cat Copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	if (this != &other)
	{
		delete(brain);
		brain = new Brain(*other.brain);
	}
	return(*this);
}

Cat:: ~Cat()
{
	delete(brain);
	std::cout<< "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return brain;
}