#include <iostream>
#include <string>

const std::string file_name_from_user()
{
	std::string file_name;
	std::cout << std::endl << " Enter the name of the file" << std::endl;
	std::cout << " for example: test.txt / test.wav" << std::endl;
	std::cin >> file_name;
	return file_name;
}