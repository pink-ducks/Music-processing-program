#include "save_as_txt.h"
#include "file_support.h"
#include "display_formatting.h"
#include "create_music.h"
#include "play_music.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

bool getconchar(KEY_EVENT_RECORD& krec)
{
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL)
	{
		return false; // console not found
	}

	for (; ;)
	{
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false;
}

void save_as_txt()
{
	std::vector<char> keys;
	std::string file_name;
	clear_screen();

	save_to_vector(keys);
	play_users_music(keys);
	file_name = file_name_from_user();
	save_to_file(keys, file_name);
}

void save_to_file(const std::vector<char> keys, const std::string file_name)
{
	std::ofstream myfile;

	myfile.open("../../UserMusic/" + file_name);
	if (myfile)
	{
		for (auto i = keys.begin(); i != keys.end(); ++i)
		{
			myfile << *i;
		}
	}
	else
	{
		std::cout << "Problem with file opening ";
	}
	myfile.close();
}
void read_from_file(const std::string file_name)
{
	std::ifstream myfile;
	myfile.open("../../UserMusic/" + file_name); 
	if (myfile)
	{
		char c;
		while (myfile.get(c))
		{
			play_sound(c);
		}
	}
	else
	{
		std::cout << "unable to open file" << std::endl;
	}
	myfile.close();
}
void load_from_file()
{
	std::string file_name;
	clear_screen();
	file_name = file_name_from_user();
	read_from_file(file_name);
}