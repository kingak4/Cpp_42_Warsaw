#include "Fixed.hpp"

Fixed:: Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->value = other.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return(*this);
	this->value = other.value;
	return(*this);
}

int Fixed:: getRawBits(void) const
{
	std :: cout << "getRawBits member function called" << std::endl;
	return(value); 
}

void Fixed::setRawBits(int const raw)
{
	std :: cout << "setRawBits member function called" << std::endl;
	value = raw;
}

