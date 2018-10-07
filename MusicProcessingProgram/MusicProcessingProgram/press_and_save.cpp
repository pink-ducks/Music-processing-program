#include "press_and_save.h"
#include "file_support.h"
#include <fstream>
#include <iostream>
#include <string>
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

void press_and_save_to_file() {
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	std::ofstream myfile;
	std::string file_path = file_path_from_user();
	myfile.open(file_path);
	if (myfile)
	{
		std::cout << " Play music on your keyboard! " << std::endl;
		std::cout << " If you're done, press ENTER " << std::endl;
		do
		{
			getconchar(key);
			if (key.wVirtualKeyCode != VK_RETURN) {
				std::cout << "You pressed and saved to file : " << key.uChar.AsciiChar << std::endl;
				myfile << key.uChar.AsciiChar;
			}
			if (key.wVirtualKeyCode == VK_RETURN) {
				std::cout << std::endl << "Your music is saved in your file!" << std::endl;
			}
		} while (key.wVirtualKeyCode != VK_RETURN);
	}
	else
	{
		std::cout << "Problem with file opening ";
	}
	myfile.close();
}