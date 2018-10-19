#include "set_menu_strings.h"
#include <vector>
#include <string>

std::vector<std::string> return_main_menu()
{
	std::vector<std::string> main_menu_strings
	{
		"> Create new sounds!",
		"  Play music from a file",
		"  Quit :("
	};
	return main_menu_strings;
}

std::vector<std::string> return_save_menu()
{
	std::vector<std::string> save_menu_strings
	{
		"> Save as .wav",
		"  Save as .txt",
		"  Back"
	};
	return save_menu_strings;
}

std::vector<std::string> return_load_menu()
{
	std::vector<std::string> load_menu_strings
	{
		"> Load from .wav",
		"  Load from .txt",
		"  Back"
	};
	return load_menu_strings;
}