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
	const int  numAnimals = 100;
	Animal *animals[numAnimals];
	
	for (int i = 0; i < numAnimals / 2; ++i)
	animals[i] = new Dog();
	for (int i = numAnimals / 2; i < numAnimals; ++i)
	animals[i] = new Cat();
	animals[0]->makeSound();
	for (int i = 0; i < numAnimals; i ++)
	delete animals[i];
}
	// Animal* a = new Animal();
	// Animal* c = new Cat();
	// Animal* d = new Dog();
	
	// std::cout << c->getType() << std::endl;
	// std::cout << d->getType() << std::endl;
	// a->makeSound();
	// c->makeSound();
	// d->makeSound();

	// WrongAnimal* wa = new WrongAnimal();
	// WrongAnimal* wc = new WrongCat();
	
	// std::cout << wa->getType() << std::endl;
	// std::cout << wc->getType() << std::endl;
	// wa->makeSound();
	// wc->makeSound();
	// delete(a);
	// delete(c);
	// delete(d);
	// delete(wa);
	// delete(wc);