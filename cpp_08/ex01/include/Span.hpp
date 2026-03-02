#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
// #include <algorithm>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other) = delete;
		~Span();

		void 			addNumber(const unsigned int value);
		unsigned int 	shortestSpan();
		unsigned int 	longestSpan();
		unsigned int	spanFill(); 									// dummy function, still TBD
		class NotEnoughNumbersStored : public std::exception {
			public:
				const char* what() const noexcept override {
					return ("1 or less numbers stored, can't provide spans");
				}
		};
	private:
		const unsigned int 	_max;
		std::vector<int>	_values;
};

#endif