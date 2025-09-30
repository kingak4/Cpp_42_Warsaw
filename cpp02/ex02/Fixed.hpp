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
			int operator>(const Fixed &other)const;
			int operator<(const Fixed &other) const;
			int operator>=(const Fixed &other) const;
			int operator<=(const Fixed &other) const;
			int operator==(const Fixed &other) const;
			int operator!=(const Fixed &other) const;
			Fixed operator+(const Fixed &other) const;
			Fixed operator-(const Fixed &other) const; 
			Fixed operator*(Fixed const &other) const; 
			Fixed operator/(const Fixed &other) const;
			Fixed &operator++(void);
			Fixed &operator--(void);
			Fixed operator++(int);
			Fixed operator--(int);
			static Fixed &min(Fixed &f1, Fixed &f2);
			static Fixed &max(Fixed &f1, Fixed &f2);
			static const Fixed &min(const Fixed &f1, const Fixed &f2);
			static const Fixed &max(const Fixed &f1, const Fixed &f2);
};
std::ostream &operator<<(std::ostream &stream, Fixed const &fixed);

#endif