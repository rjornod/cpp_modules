#include "../include/Harl.hpp"

int main(int argc, char **argv)
{
	//(void)argc;
	Harl harl;
	std::string level;
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return (0);
	}
	else if (argc < 2)
	{
		std::cout << "No argument provided" << std::endl;
		return (0);
	}
	
	level = argv[1];
	
	harl.complain(level);
}