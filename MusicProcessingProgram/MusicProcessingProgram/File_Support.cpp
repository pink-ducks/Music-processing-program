#include <iostream>
#include <string>

std::string file_path_from_user()
{
	std::string path;
	std::cout << std::endl << " Enter the file name or file path" << std::endl;
	std::cout << " for example: test.txt" << std::endl;
	std::cin >> path;
	return path;
}