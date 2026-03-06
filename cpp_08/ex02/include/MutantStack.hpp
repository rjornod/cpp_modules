#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack& other) : std::stack<T>(other) 				// calls base class copy constructor
		{
		};
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		};

		// typename is required in the return type becasue T is unknown at compile time and the compiler needs that to know that ::iterator refers to a type, not a static variable
		typename std::stack<T>::container_type::iterator begin() {return this->c.begin();}	// returns an iterator to the first element. exposed from std::deque which stack is based on
		typename std::stack<T>::container_type::iterator end() {return this->c.end();} 		// returns an iterator to the last element. also exposed from std::deque.
		using iterator = typename std::stack<T>::container_type::iterator;					// creates an alias from the typename above
};

#endif