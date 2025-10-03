#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout<< "Dog constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Dog Copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	if (this != &other)
	{
		delete(brain);
		brain = new Brain(*other.brain);
	}
	return(*this);
}

Dog:: ~Dog()
{
	delete(brain);
	std::cout<< "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return brain;
}
