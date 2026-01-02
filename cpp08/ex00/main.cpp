#include "easyfind.hpp"

int main()
{
	std::list<int> a;
	a.push_front(4);
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);

	std::vector<int> b;
	b.push_back(5);
	b.push_back(6);
	b.push_back(7);
	b.push_back(8);
	try
	{
		std::list<int>::iterator item = easyfind(a, 3);
		std::cout << *item << std::endl;
		item = easyfind(a, 4);
		std::cout << *item << std::endl;
		item = easyfind(a, 7);
		std::cout << *item << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator item = easyfind(b, 5);
		std::cout << *item << std::endl;
		item = easyfind(b, 6);
		std::cout << *item << std::endl;
		item = easyfind(b, 10);
		std::cout << *item << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
