#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>
#include <stdexcept>


class Span
{
	private:
		unsigned int max_i;
		std::vector<int>	nb;

	public:
		Span();
		Span(unsigned int max_numbers);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int num);
		void addNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif

