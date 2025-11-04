#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define RED "\033[1;31m"
#define WHITE "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int	argCheck(int argc)
{
	if (argc != 4)
	{
		std::cout << RED << "Incorrect number of arguments provided" << WHITE << std::endl;
		return (0);
	}
	return (1);
}

int fileCheck(std::ifstream &infile, std::ofstream &outfile, std::string &search_word)
{
	if ( infile.fail() || !infile.is_open())
	{
		std::cout << RED << "Problem opening the infile" << WHITE << std::endl;
		return (0);
	}
	if ( outfile.fail() || !outfile.is_open())
	{
		std::cout << RED << "Problem opening the outfile" << WHITE << std::endl;
		return (0);
	}
	if (search_word.empty())
	{
		std::cout << RED << "Can't search for an empty string" << WHITE << std::endl;
		return (0);
	}
	return (1);
}

std::string	replaceWord(std::ifstream &infile, std::string replacement_word, std::string search_word)
{
	std::string original_line;
	std::string new_line;
	size_t 		pos;
	size_t 		start;

	while (std::getline(infile, original_line))
	{
		pos = 0;
		start = 0;
		while ((pos = original_line.find(search_word, pos)) != std::string::npos)
		{
			new_line += original_line.substr(start, (pos - start));
			new_line += (replacement_word);
			
			pos = pos + search_word.length();
			start = pos;
		}
		new_line += original_line.substr(start);
		new_line += "\n";
	}
	return new_line;

}

/*******************************************************************************************
 * 
 * 	Notes: 
 * 		+= and append() do the same thing (adding data at the end of a string)
 * 		The key difference would be that append() gives you extra options, such as 
 * 	specifying indexes and lengths allowing only parts of a string to be appended
 * 		+= is limited to appending full strings
 * 
 * 	ifstream: "input file stream". is used to read data from files
 * 	ofstream: "output file stream". used to output data to a file
 * 	fstream: "file stream". can do both operations
 * 
 * 	find(): used to find a substring or character in a target string. if found return the position
 * of the first character of the substring 
 * 	npos: value returned by some functions like find() to indicate that a search operation did
 * not find a match
 *******************************************************************************************/
int	main(int argc, char **argv)
{
	if(!argCheck(argc))
		exit(0);
	std::string new_file_name = argv[1]; // convert argv[1] (file name) to a string so it can be used as the file name for the output file
	std::ifstream infile(argv[1]);
	std::ofstream outfile(new_file_name.append(".replace"));
	std::string search_word = argv[2];
	std::string replacement_word = argv[3];
	
	if(!fileCheck(infile, outfile, search_word))
		exit(0);
	else
		outfile << replaceWord(infile, replacement_word, search_word);
	outfile.close();
	infile.close();
}
