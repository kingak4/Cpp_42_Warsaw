#include "Span.hpp"

Span::Span() : max_i(0) {};

Span::Span(unsigned int max_numbers) :  max_i(max_numbers) {};

Span::Span(const Span &other)
{
	max_i = other.max_i;
	nb = other.nb;
}

Span::Span &operator=(const Span &other)
{
	if(this != &other)
	{
		max_i = other.max_i;
		nb = other.nb;
	}
	return(*this);
}
Span::~Span(){};

void Span::addNumber(int num)
{
	if(nb.size() >= max_i)
		throw(std::runtime_error("Already full!"));
	nb.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to)
{
	int i = 0;
	std::vector<int>::iterator tmp = from;
	while(tmp != to)
	{
		i++;
		tmp++;
	}
	if(nb.size() + i > max_i)
		throw(std::runtime_error("Already full!"));
	while (from != to) 
	{
		nb.push_back(*from);
		from++;
	}
}

unsigned int Span::shortestSpan();
unsigned int Span::longestSpan();