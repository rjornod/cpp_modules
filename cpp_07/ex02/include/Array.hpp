#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
	private:
		T 	*_array;
		int	_size;

	public:

    	Array() : _array(nullptr), _size(0) {};

		Array(unsigned int n) : _array(new T[n]()), _size(n) {};
    
    	Array(const Array& other) : _array(nullptr), _size(other._size)
		{
			std::cout << "startiing to copy..." << std::endl;
			if (_size > 0)
			{
				this->_array = new T[_size];
				for (int i = 0; i < _size; i++)
				{
					std::cout << "copying..." << std::endl;
					this->_array[i] = other._array[i];
					std::cout << "copied..." << std::endl;
				}
			}
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				for (int i = 0; i < _size; i++)
				{
					this->_array[i] = other._array[i];
				}
			}
			return *this;
		}

		~Array()
		{
			delete[] _array;
		};

		int size()
		{
			return (_size);
		}
		T& operator[](int index)
		{
			if (index >= _size || index < 0)
				throw std::out_of_range("Index out of bounds");
			return (_array[index]);
		};
};


#endif
