#pragma once

#include <iostream>
#include <stdint.h>


typedef struct data
{
	int age;
	std::string name;
} t_data;
	

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer& operator=(const Serializer &src);

	public:
		static uintptr_t serialize(data *ptr);
		static t_data *deserialize(uintptr_t raw);
};
