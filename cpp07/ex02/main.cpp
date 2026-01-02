#include "Array.hpp"

int main()
{
	int i = 0;
	Array<int> a(5);

	while (i < 5)
	{
		std::cout << a[i];
		i++;
	}
	std::cout << std::endl;
	a[0] = 10;
	a[1] = -11;
	a[2] = 12;
	a[3] = 100;
	a[4] = 22;
	i = 0;
	while (i < 5)
	{
		std::cout << a[i];
		i++;
		std::cout << std::endl;
	}
	Array<int> b(2);
	b[0] = 1;
	b[1] = 2;
	try
	{
		b[10] = 10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Array<int> c = b;
	std::cout<< c[0] << std::endl;
	try
	{
		c[0] = 15;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<< c[0] << std::endl;
	const Array<int> d = b;
	std::cout << d[0] << std::endl;
	std::cout << "Array a size = " << a.size() << std::endl;
	std::cout << "Array b size = "<< b.size() << std::endl;
	std::cout << "Array c size = " << c.size() << std::endl;

	i = 0;
	Array<double> db(3);
	db[0] = 90.90;
	db[1] = 222.22;
	db[2] = 902.373;
	while (i < 3)
	{
		std::cout << db[i];
		i++;
		std::cout << std::endl;
	}
	i = 0;
	Array<std::string > str(3);
	str[0] = "Hi";
	str[1] = "How are you?";
	str[2] = "Have a nice day :)";
	while (i < 3)
	{
		std::cout << str[i];
		i++;
		std::cout << std::endl;
	}
	std::cout << "Array double size = "<< db.size() << std::endl;
	std::cout << "Array string size = " << str.size() << std::endl;

	Array<int> e = a;
	std::cout << "size a = " << a.size() << " size e = " << e.size()<<std::endl;
	e[0] = 21;
	std::cout<< e[0] <<std::endl;
	std::cout<< a[0] <<std::endl;

}
