#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename U>
void iter(T* array, size_t len, U function)
{
	size_t i = 0;
	while(i < len)
	{
		function(array[i]);
		i++;
	}
}

#endif