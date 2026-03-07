#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <exception>
# include <algorithm>


class ValueNotFound : public std::exception {
			public:
				const char* what() const noexcept override {
					return ("Value not found");
				}
};

template<typename T>
void easyfind(const T& intContainer, int findMe)
{
	auto begin = intContainer.begin();
	auto end = intContainer.end();
	auto find = std::find(begin, end, findMe);
	if ( find != end)
		std::cout << "Found the value "<< findMe << " in position " << std::distance(begin, find) <<std::endl;
	else
		throw ValueNotFound();
}

#endif
