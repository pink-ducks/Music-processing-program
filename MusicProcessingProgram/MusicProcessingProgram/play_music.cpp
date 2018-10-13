#include "play_music.h"
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <crtdbg.h>
#include <vector>

std::string find_sound(const char key)
{
	std::string sound_path;
	switch (key)
	{
	case 'q':
		sound_path = "../../Sounds/18V_Cordless_Drill_Switch.wav";
		break;
	case 'w':
		sound_path = "../../Sounds/Auto_Bullets_Flyby_Short.wav";
		break;
	case 'e':
		sound_path = "../../Sounds/Bee_Buzz.wav";
		break;
	case 'r':
		sound_path = "../../Sounds/Beep_Short.wav";
		break;
	default:
		break;
	}
	return sound_path;
}

void play_sound(const char key)
{
	std::string sound_path;
	sound_path = find_sound(key);
	if (sound_path.size() != 0)
	{
		// converting std::string to LPCWSTR
		std::wstring stemp = std::wstring(sound_path.begin(), sound_path.end());
		LPCWSTR path = stemp.c_str();

		std::cout << " *music*" << std::endl;
		PlaySound(path, NULL, SND_SYNC);
	}
	else
	{
		std::cout << " *error*" << std::endl;
	}

}

void play_users_music(std::vector<char> keys) 
{

	for (auto i = keys.begin(); i != keys.end(); ++i)
	{
		play_sound(*i);
	}
}