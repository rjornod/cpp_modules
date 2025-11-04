#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int		i, x;
	char	ch;
	if (argc == 1)	
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE"; 
	else	
	{
		for (i = 1; i < argc; i++) 
		{
			int len = strlen(argv[i]);
			for (x = 0; x < len; x++)
			{
				ch = toupper(argv[i][x]);
				std::cout << ch;
			}
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << "\n"; 
	return (0);
}