#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
		unsigned int _ideasNr;
	public:
		Brain();
		~Brain();
		Brain operator=(const Brain& other);
		Brain(const Brain& copy);

		void setIdea(const std::string& idea);
		void printIdea(unsigned int amount);
};

#endif