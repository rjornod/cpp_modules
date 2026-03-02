#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <exception>


class ValueNotFound : public std::exception {
			public:
				const char* what() const noexcept override {
					return ("Value not found");
				}
};

template<typename T>
void easyfind(T intContainer, int findMe)
{
	for (int x : intContainer)
	{
		if (x == findMe)
		{
			std::cout << "You found me" << std::endl;
			return;
		}
	}
	throw ValueNotFound();
}

#endif
