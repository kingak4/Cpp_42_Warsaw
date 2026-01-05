#include "MutantStack.hpp"

int main()
{
	std::cout << "Subject tests:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "My tests:" << std::endl;
	MutantStack<int> k;
	if(k.empty())
		std::cout << "Stack is empty" << std::endl;
	else
		std::cout << "Stack has elements" << std::endl;
	k.push(1);
	k.push(2);
	k.push(3);
	k.push(4);
	k.push(5);
	MutantStack<int>::iterator first = k.begin();
	MutantStack<int>::iterator last = k.end();
	std::cout << "Now stack has elements : ";
	while (first != last)
	{
		std::cout << *first<< " ";
		++first;
	}
	std::cout << std::endl;
	std::cout << "Stack size : "<< k.size() << std::endl;
	k.pop();
	std::cout << "After delated one number the last nmber is = "<<k.top() << std::endl;
	std::cout << "Now size is  "<< k.size() << std::endl;
	std::cout << "begin is " << *k.begin() << std::endl;
	return (0);
}