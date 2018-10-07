
#include <stdlib.h>  
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <string>

std::string File_path_from_user()
{
	std::ifstream infile;
	while (true)
	{
		std::string infilename;
		getline(std::cin, infilename);
		infile.open(infilename.c_str());
		if (infile) return infilename;
		std::cout << "Invalid file. Please enter a valid input file name" << std::flush;
	}
}