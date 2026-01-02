#ifndef ARRAY_HPP
# define ARRAY_HPP


# include <iostream>
# include <string>
#include <exception>

template<typename T>
class Array
{
	private:
			T *elements;
			size_t count;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
		~Array();
		unsigned int	size() const;
	class InvalidIndexException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Index too high!");
			}
	};
};


# include "Array.tpp"

#endif