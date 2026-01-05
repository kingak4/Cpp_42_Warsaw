#include "Span.hpp"

Span::Span() : max_i(0) {};

Span::Span(unsigned int max_numbers) :  max_i(max_numbers) {};

Span::Span(const Span &other)
{
	max_i = other.max_i;
	nb = other.nb;
}

Span& Span::operator=(const Span &other)
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

unsigned int Span::shortestSpan()
{
	std::vector<int> copy = nb;
	unsigned int i = 0 ;
	unsigned int miniSpan = 2147483647;

	if(nb.size() < 2)
		throw(std::runtime_error("Need more numbers"));
	sort(copy.begin(), copy.end());
	while(i < copy.size() -1 )
	{
		unsigned int r = copy [i +1] - copy[i];
		if(r < miniSpan)
			miniSpan = r;
		i++;
	}
	return(miniSpan);
}

unsigned int Span::longestSpan()
{
	unsigned int i = 0;
	int r = 0;
	int max = nb[0];
	int min = nb[0];

	if(nb.size() < 2)
		throw(std::runtime_error("Need more numbers"));
	while(i < nb.size())
	{
		if(nb[i] < min)
			min = nb[i];
		if(nb[i] > max)
			max = nb[i];
		i++;
	}
	r = max - min;
	return(r);
}
