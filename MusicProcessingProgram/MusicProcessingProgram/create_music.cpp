#include "create_music.h"
#include "save_as_txt.h"
#include <iostream>
#include <Windows.h>

void save_to_vector(std::vector<char> & keys)
{
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };

	std::cout << " Play music on your keyboard! " << std::endl;
	std::cout << " If you're done, press ENTER " << std::endl;
	do {
		getconchar(key);
		if (key.wVirtualKeyCode != VK_RETURN) {
			std::cout << "You pressed " << key.uChar.AsciiChar << std::endl;
			keys.push_back(key.uChar.AsciiChar);
		}
		if (key.wVirtualKeyCode == VK_RETURN) {
			std::cout << std::endl << "Your music is ready!" << std::endl;
		}

	} while (key.wVirtualKeyCode != VK_RETURN);
}