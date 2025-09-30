#include "Fixed.hpp"

Fixed:: Fixed(int i)
{
	value = i << bits;
	std::cout << "Int constructor called" << std::endl;
}
Fixed:: Fixed(float n)
{
	n = n * 256;
	value = (roundf(n));
	std::cout << "Float constructor called" << std::endl;
}

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
float Fixed:: toFloat(void) const
{
	float n = this->value;
	n = n / 256;
	return(n);
}

int Fixed:: toInt(void) const
{
	int i = this->value;
	i = i >> bits;
	return(i);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	float n = fixed.toFloat();
	stream << n;
	return(stream);
}

int Fixed::operator>(const Fixed &other)const
{
	return(this->value > other.value);
}

int Fixed::operator<(const Fixed &other) const
{
	return(this->value < other.value);
}

int Fixed::operator>=(const Fixed &other) const
{
	return(this->value >= other.value);
}

int Fixed::operator<=(const Fixed &other) const
{
	return(this->value <= other.value);
}

int Fixed::operator==(const Fixed &other) const
{
	return(this->value == other.value);
}

int Fixed::operator!=(const Fixed &other) const
{
	return(this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return(*this);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value++;
	return(temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value--;
	return(temp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return(f1);
	return(f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return(f1);
	return(f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return(f1);
	return(f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return(f1);
	return(f2);
}
