#include "../include/Serializer.hpp"

int main(void)
{
	Serializer::Data data;
	data.value = 3;

	uintptr_t serial = Serializer::serialize(&data);
	std::cout << serial << std::endl;
	Serializer::Data* deserial = Serializer::deserialize(serial);
	std::cout << deserial->value << std::endl;
}