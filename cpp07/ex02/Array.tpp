#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>
Array<T>::Array(): elements(NULL), count(0) {};

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), count(n) {};

template<typename T>
Array<T>::~Array()
{
	delete[] elements;
};

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if(i < count)
		return(elements[i]);
	throw InvalidIndexException();
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if(i < count)
		return(elements[i]);
	throw InvalidIndexException();
}

template<typename T>
unsigned int Array<T>::size() const
{
	return(count);
}

template<typename T>
Array<T>::Array(const Array &other)
{
	size_t i = 0;

	count = other.count;
	elements = new T[count]();
	while(i < count)
	{
		elements[i] = other.elements[i];
		i++;
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	size_t i = 0;

	if(this != &other)
	{
		delete[] elements;
		count = other.count;
		elements = new T[count]();
		while(i < count)
		{
			elements[i] = other.elements[i];
			i++;
		}
	}
	return(*this);
}

#endif