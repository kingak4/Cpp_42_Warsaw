#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
			int value;
			static const int bits = 8;
	public:
	 		Fixed(int i);
			Fixed(float n);
			Fixed();
			Fixed &operator=(const Fixed &other);
			Fixed(const Fixed &other);
			~Fixed(); 
			int getRawBits(void) const;
			void setRawBits(int const raw);
			float toFloat(void) const;
			int toInt(void) const;
};
std::ostream &operator<<(std::ostream &stream, Fixed const &fixed);

#endif