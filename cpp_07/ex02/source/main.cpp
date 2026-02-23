#include <iostream>
#include <Array.hpp>

#define MAX_VAL 5
int main(int, char**)
{
	// Array<int> test(2);
	// std::cout << test.size() <<std::endl;

	Array<int> intarray(4);
	std::cout  <<" size of array is: " << intarray.size() <<std::endl;
	for (int i = 0; i < intarray.size(); i++)
    {
        const int value = rand() % 100;
        intarray[i] = value;
 
		std::cout << intarray[i] << std::endl;
	}

	std::cout << "changing intarray[1] to 101...." << std::endl;
	for (int i = 0; i < intarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << intarray[i] << std::endl;
	}
	
	std::cout << "creating new array ...." << std::endl;
	Array<int> newarray(intarray);
	for (int i = 0; i < newarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << newarray[i] << std::endl;
	}
	intarray[1] = 101;
	std::cout << "checking original array" <<std::endl;
	for (int i = 0; i < intarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << intarray[i] << std::endl;
	}
	std::cout << "checking new array" <<std::endl;
	for (int i = 0; i < newarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << newarray[i] << std::endl;
	}
	intarray = newarray;
	std::cout << "checking original array after copy assignment" <<std::endl;
	for (int i = 0; i < intarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << intarray[i] << std::endl;
	}
	std::cout << "checking new array after copy assignment" <<std::endl;
	for (int i = 0; i < newarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << newarray[i] << std::endl;
	}
	intarray[1] = 101;
	std::cout << "checking original array after modifying 1" <<std::endl;
	for (int i = 0; i < intarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << intarray[i] << std::endl;
	}
	std::cout << "checking new array after moddifying 1" <<std::endl;
	for (int i = 0; i < newarray.size(); i++)
    {
        // const int value = rand() % 100;
        // intarray[i] = value;
 
		std::cout << newarray[i] << std::endl;
	}
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	int * a = new int[5];
	std::cout << "*a = " << *a <<std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
		std::cout << numbers[i] << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		else
			std::cout << "Both elements are equal" << std::endl;
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	delete [] a;
	// delete [] intarray;
	// delete [] newarray;
    return 0;
}