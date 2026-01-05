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

// -------------------------
// Funkcja begin()
// -------------------------
// - Zwraca iterator na początek stosu
// - Korzysta z kontenera bazowego std::stack<T>::c
// - Zwraca this->c.begin()

// -------------------------
// Funkcja end()
// -------------------------
// - Zwraca iterator na koniec stosu
// - Korzysta z kontenera bazowego std::stack<T>::c
// - Zwraca this->c.end()

#endif