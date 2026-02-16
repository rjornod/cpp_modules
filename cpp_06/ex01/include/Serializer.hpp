#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

class Serializer
{
private:
    // Default Constructor
    Serializer();
    
    // Copy Constructor
    Serializer(const Serializer& other);
    
    // Copy Assignment Operator
    Serializer& operator=(const Serializer& other);
    
    // Destructor
    ~Serializer();
public:


	struct Data
	{
		int value;
	};

	static Data* deserialize(uintptr_t raw);
	static uintptr_t serialize(Data* ptr);


};

#endif
