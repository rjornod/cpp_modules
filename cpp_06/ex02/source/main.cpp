#include "../include/Base.hpp"
#include <stdlib.h>

int main(void)
{
	srand(time(0));
	Base base;
	Base *base2 = base.generate();
	base.identify(base2);
	base.identify(*base2);

	delete base2;
}