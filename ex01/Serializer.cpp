#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}

Serializer::Serializer( const Serializer &cpy)
{
	*this = cpy;
}

Serializer& Serializer::operator=( const Serializer &cpy)
{
	(void)cpy;
	return *this;
}

uintptr_t Serializer::serialize(data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data *>(raw));
}
