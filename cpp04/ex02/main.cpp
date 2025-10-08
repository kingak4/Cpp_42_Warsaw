#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <string>
#include "Brain.hpp"
#include <iostream>

int main()
{
	Animal *cat = new Cat();
	Animal *dog = new Dog();
	delete(cat);
	delete(dog);
}
