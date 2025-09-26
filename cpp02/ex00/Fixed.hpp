#ifndef FIXED_CPP
# define FIXED_CPP

#include <iostream>
#include <string>

class Fixed
{
	private:
			int value;
			static const int bits = 8;
	public:
			// getRawBits() – zwraca _value (niczego nie zmienia → const).
			// setRawBits(int const raw) – ustawia _value.
			Fixed();
			Fixed(const Fixed &other); // copy constructor
			~Fixed(); // destructor
			Fixed &operator=(const Fixed &other); // copy assignment
			int getRawBits(void) const;
			void setRawBits(int const raw);
};

#endif