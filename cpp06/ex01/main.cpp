#include <string>
#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t ptr;
	Data *otherdata;

	data.age = 20;
	data.name = "Kinga";
	std::cout << "Address of data: " << &data << std::endl;
	std::cout << "Data before serialize: " << data.name << ", " << data.age << std::endl;
	ptr = Serializer::serialize(&data);
	std::cout << "Serialized value (uintptr_t): " << ptr << std::endl;
	otherdata = Serializer::deserialize(ptr);
	std::cout << "Address after deserialize: " << otherdata << std::endl;
	std::cout << "Data after deserialize: " << otherdata->name << ", " << otherdata->age << std::endl;
}