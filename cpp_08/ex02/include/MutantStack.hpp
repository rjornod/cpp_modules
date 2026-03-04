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
		MutantStack(const MutantStack& other){};
		MutantStack& operator=(const MutantStack& other){};
		typename std::stack<T>::container_type::iterator begin() {return this->c.begin();}
		typename std::stack<T>::container_type::iterator end() {return this->c.end();}
	private:
};

#endif