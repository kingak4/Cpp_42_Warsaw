#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &other)
{
	*this = &other;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) : std::stack<T>(other) {};

template<typename T>
MutantStack<T>:: ~MutantStack() {};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return(this->c.begin());
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return(this->c.end());
}

#endif