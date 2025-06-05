#include "Serializer.hpp"

int main (void)
{
	t_data data;
	uintptr_t ptr;
	t_data *empty;

	data.age = 19;
	data.name = "Solanum";

	std::cout <<  "DATA VALUES " << std::endl << std::endl << std::endl;
	std::cout << "age : " << data.age << std::endl;
	std::cout << "name : "  << data.name << std::endl;

	ptr = Serializer::serialize(&data);

	std::cout << std::endl << "DATA POINTERS " << std::endl << std::endl << std::endl;
	std::cout << "ptr : " << ptr << std::endl;
	std::cout << "original : " << &data << std::endl;

	empty = Serializer::deserialize(ptr);

	std::cout << std::endl << "EMPTY VALUES " << std::endl << std::endl << std::endl;
	std::cout << "age : " << empty->age << std::endl;
	std::cout << "name : "  << empty->name << std::endl;

}
