#include "Brain.hpp"

Brain::Brain()
{
	std::cout<< "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	int i = 0;
	while(i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	std::cout<< "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) 
{
	if(this == &other)
		return (*this);
	int i = 0;
	while(i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout<< "Brain destructor called" << std::endl;
}
const std::string *Brain::getIdeas(void) const
{
	return (ideas);
}