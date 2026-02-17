#include "../include/Serializer.hpp"

uintptr_t Serializer::serialize(Serializer::Data *ptr)													// converts from pointer to uintptr_t
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer::Data* Serializer::deserialize(uintptr_t raw)												// converts from uintptr_t to pointer
{
	return (reinterpret_cast<Serializer::Data*>(raw));
}
