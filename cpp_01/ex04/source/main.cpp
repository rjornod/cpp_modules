#include <iostream>
#include <fstream>


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
				//std::cout << "Found word at: " << pos << std::endl;
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
