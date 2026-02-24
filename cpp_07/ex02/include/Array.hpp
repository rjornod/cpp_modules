#ifndef ARRAY_HPP
# define ARRAY_HPP
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUEBG "\033[44m"
#define BLACKBG "\033[0m"
#define REDBG "\033[40m"
#define GREENBG "\033[42m"


# include <iostream>

template<class T>
class Array
{
	private:
		T 	*_array;
		unsigned int	_size;

	public:

    	Array() : _array(nullptr), _size(0) {};

		Array(unsigned int n) : _array(new T[n]()), _size(n) {};			// the '()' in 'new T[n]()' initializes the values in the array to 0 for built in types (char, int, etc)

    	Array(const Array& other) : _array(nullptr), _size(other._size)
		{
			if (_size > 0)
			{
				this->_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					this->_array[i] = other._array[i];
			}
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete [] _array;
				this->_size = other._size;
				if (this->_size > 0)
				{
					this->_array = new T[_size];
					for (int i = 0; i < _size; i++)
						this->_array[i] = other._array[i];
				}
				else
					this->_array = nullptr;
			}
			return *this;
		}

		~Array()
		{
			delete[] _array;
		};

		unsigned int size() const
 		{
			return (_size);
		}

		T& operator[](unsigned int index)											// subscript operator overload, checks the the index and if its out of bounds it throws an exception
		{
			if (index >= _size || index < 0)
				throw std::out_of_range("Index out of bounds");
			return (_array[index]);
		};

		const T& operator[](unsigned int index)	const								// const subscript operator overload, checks the the index and if its out of bounds it throws an exception
		{
			if (index >= _size || index < 0)
				throw std::out_of_range("Index out of bounds");
			return (_array[index]);
		};
};


#endif
