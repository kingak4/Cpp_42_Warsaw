#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int r = 0;

	r = rand() % 3;
	if(r == 0)
		return(new A());
	else if(r == 1)
		return(new B());
	else
		return(new C());
}

void identify(Base *p)
{
	if(dynamic_cast <A*>(p))
		std::cout << "Pointer identified as A" << std::endl;
	else if(dynamic_cast <B*>(p))
		std::cout << "Pointer identified as B" << std::endl;
	else if(dynamic_cast <C*>(p))
		std::cout << "Pointer identified as C" << std::endl;
}
void identify(Base& p)
{
	Base* ptr = &p;
	if(dynamic_cast <A*>(ptr))
		std::cout << "Identified as A" << std::endl;
	else if(dynamic_cast <B*>(ptr))
		std::cout << "Identified as B" << std::endl;
	else if(dynamic_cast <C*>(ptr))
		std::cout << "Identified as C" << std::endl;
}
int main()
{
	srand(time(0));
	int i = 0;
	while(i < 2)
	{
		Base* pp = generate();
		identify(pp);
		identify(*pp);
		delete(pp);
		i++;
	}
}