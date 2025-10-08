#include "../include/Harl.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	Harl harl;
	std::string level;
	
	level = argv[1];
	
	harl.complain(level);
}