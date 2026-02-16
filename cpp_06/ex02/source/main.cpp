#include "../include/Base.hpp"

int main(void)
{
	srand(time(0));
	Base base;
	Base *base2 = base.generate();
	base.identify(base2);
}