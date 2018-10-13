#include <iostream>
#include <string>

const std::string file_name_from_user()
{
	std::string file_name;
	std::cout << std::endl << " Enter the file name or file path" << std::endl;
	std::cout << " for example: test.txt" << std::endl;
	std::cin >> file_name;
	return file_name;
}