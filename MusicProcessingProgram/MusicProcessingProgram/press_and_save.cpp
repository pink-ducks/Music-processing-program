#include "press_and_save.h"
#include <fstream>
#include <iostream>
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

void PressAndSaveToFile() {
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	std::ofstream myfile;
	myfile.open("example.txt");

	do
	{
		getconchar(key);
		if (key.wVirtualKeyCode != VK_RETURN) {
			std::cout << "You pressed and saved to file : " << key.uChar.AsciiChar << std::endl;
			myfile << key.uChar.AsciiChar << std::endl;
		}
		if (key.wVirtualKeyCode == VK_RETURN) {
			std::cout << "You finished !" << std::endl;
			myfile.close();
		}
	} while (key.wVirtualKeyCode != VK_RETURN);

}
