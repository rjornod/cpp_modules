#include "../include/Serializer.hpp"

// Default Constructor
Serializer::Serializer() {
    std::cout << "Serializer default constructor called" << std::endl;
}

// Copy Constructor
Serializer::Serializer(const Serializer& other) {
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = other;
}

// Copy Assignment Operator
Serializer& Serializer::operator=(const Serializer& other) {
    std::cout << "Serializer copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy attributes here
    }
    return *this;
}

// Destructor
Serializer::~Serializer() {
    std::cout << "Serializer destructor called" << std::endl;
}


uintptr_t Serializer::serialize(Serializer::Data *ptr)													// converts from pointer to uintptr_t
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer::Data* Serializer::deserialize(uintptr_t raw)												// converts from uintptr_t to pointer
{
	return (reinterpret_cast<Serializer::Data*>(raw));
}
