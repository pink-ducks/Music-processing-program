#include "set_menu_strings.h"
#include <vector>
#include <string>

std::vector<std::string> set_main_menu()
{
	std::vector<std::string> main_menu_strings
	{
		"> Create new sounds!",
		"  Play music from a file",
		"  Quit :("
	};
	return main_menu_strings;
}