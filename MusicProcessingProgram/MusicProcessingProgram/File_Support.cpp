#include "file_support.h"
#include <iostream>
#include <string>

const std::string file_name_from_user(file_type type)
{
	std::string file_name;
	if (type == WAV)
	{
		std::cout << std::endl << " Enter the name of the WAV file" << std::endl;
		std::cout << " for example: test.wav" << std::endl;
	}
	else 
	if (type == TXT)
	{
		std::cout << std::endl << " Enter the name of the TXT file" << std::endl;
		std::cout << " for example: test.txt" << std::endl;
	}
	else 
		std::cout << "ERROR: problem with getting file name from user" << std::endl;

	std::cin >> file_name;
	return file_name;
}