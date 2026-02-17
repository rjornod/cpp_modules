#include "../include/Serializer.hpp"
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main(void)
{
	Serializer::Data data;
	data.value = 3;
	std::cout << GREEN << "Original data.value: " << WHITE << data.value << std::endl;
	uintptr_t serial = Serializer::serialize(&data);
	std::cout << RED << "Serialized value: " << WHITE << serial << std::endl;
	Serializer::Data* deserial = Serializer::deserialize(serial);
	std::cout << YELLOW << "Deserialized value: " << WHITE << deserial->value << std::endl;
	std::cout << BLUE << "data.value after conversions: " << WHITE << data.value << std::endl;
}