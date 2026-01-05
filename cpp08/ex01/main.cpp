#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span nb = Span(5);
	int arr[] = {10, 20, 30, 40, 50};
	std::vector<int> values(arr, arr + 5);
	nb.addNumbers(values.begin(), values.end());
	std::cout << std::endl;
	std::cout << nb.shortestSpan() << std::endl;
	std::cout << nb.longestSpan() << std::endl;
	std::cout << std::endl;

	Span s = Span(1);
	s.addNumber(6);
	try
	{
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	Span sk = Span(3);
	try
	{
		sk.addNumber(222);
		sk.addNumber(33);
		sk.addNumber(11);
		sk.addNumber(1888);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}