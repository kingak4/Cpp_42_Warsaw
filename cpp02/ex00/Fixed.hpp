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
			Fixed();
			Fixed(const Fixed &other);
			~Fixed(); 
			Fixed &operator=(const Fixed &other);
			int getRawBits(void) const;
			void setRawBits(int const raw);
};

#endif