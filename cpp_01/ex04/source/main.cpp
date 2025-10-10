#include <iostream>
#include <fstream>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int	errorCheck(std::ifstream &infile, int argc)
{
	if ( infile.fail() || !infile.is_open())
	{
		std::cout << RED << "Problem opening file" << WHITE << std::endl;
		return (0);
	}
	if (argc < 3 || argc > 3)
	{
		std::cout << RED << "Incorrect number of arguments provided" << WHITE << std::endl;
		return (0);
	}
	return (1);
}


/**
 * 
 * 	Notes: 
 * 		+= and append() do the same thing (adding data at the end of a string)
 * 		The key difference would be that append() gives you extra options, such as 
 * 	specifying indexes and lengths allowing only parts of a string to be appended
 * 		+= is limited to appending full strings
 * 
 */
int	main(int argc, char **argv)
{
	std::string new_file_name = argv[1]; // convert argv[1] (file name) to a string to be used in ofstream
	std::ifstream infile(argv[1]);
	if (!errorCheck(infile, argc))
		return (0);
	std::ofstream outfile(new_file_name.append(".replace"));
	size_t pos = 0;
	size_t start = 0;
	std::string result;
	
	(void)argc;

	if (infile.is_open() && outfile.is_open())
	{
		std::string line;
		std::string search_word = argv[2];
		std::string replace_word = argv[3];
		std::string changed_line;

		while (std::getline(infile, line))
		{
			pos = 0;
			start = 0;
			while ((pos = line.find(search_word, pos)) != std::string::npos)
			{
				result += line.substr(start, (pos - start));
				result += (replace_word);
				
				pos = pos + search_word.length();
				start = pos;
			}
			result += line.substr(start);
			result += "\n";
			std::cout << "result: " << result << std::endl;
		}
		outfile << result;
	}
	else
	{
		std::cout << "Error opening files" << std::endl;
		return (0);
	}
}
