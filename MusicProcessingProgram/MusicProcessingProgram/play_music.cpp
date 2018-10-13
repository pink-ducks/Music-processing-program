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
		sound_path = "../../Sounds/2.6_6.wav";
		break;
	case 'w':
		sound_path = "../../Sounds/2.7_7.wav";
		break;
	case 'e':
		sound_path = "../../Sounds/2.8_8.wav";
		break;
	case 'r':
		sound_path = "../../Sounds/1.5_5.wav";
		break;
	case 't':
		sound_path = "../../Sounds/2.9_9.wav";
		break;
	case 'y':
		sound_path = "../../Sounds/1.7_7.wav";
		break;
	case 'u':
		sound_path = "../../Sounds/1.10_10.wav";
		break;
	case 'i':
		sound_path = "../../Sounds/1.8_8.wav";
		break;
	case 'o':
		sound_path = "../../Sounds/2.10_10.wav";
		break;
	case 'p':
		sound_path = "../../Sounds/3.9_9.wav";
		break;
	case 'a':
		sound_path = "../../Sounds/4.11_11.wav";
		break;
	case 's':
		sound_path = "../../Sounds/1.11_11.wav";
		break;
	case 'd':
		sound_path = "../../Sounds/1.11.2_2.wav";
		break;
	case 'f':
		sound_path = "../../Sounds/1.9_9.wav";
		break;
	case 'g':
		sound_path = "../../Sounds/Football_Punts.wav";
		break;
	case 'h':
		sound_path = "../../Sounds/Footstep_on_Cracked_Glass.wav";
		break;
	case 'j':
		sound_path = "../../Sounds/Instrument_Strum.wav";
		break;
	case 'k':
		sound_path = "../../Sounds/Machine_Gun_hit_Car.wav";
		break;
	case 'l':
		sound_path = "../../Sounds/Metal_Strike.wav";
		break;
	case 'z':
		sound_path = "../../Sounds/Metal_Twang.wav";
		break;
	case 'x':
		sound_path = "../../Sounds/Metallic_Clank.wav";
		break;
	case 'c':
		sound_path = "../../Sounds/Object_Toss_and_Smash.wav";
		break;
	case 'v':
		sound_path = "../../Sounds/Power_Tool_Electrical_Buzz.wav";
		break;
	case 'b':
		sound_path = "../../Sounds/Ratchet_Wrench_Slow.wav";
		break;
	case 'n':
		sound_path = "../../Sounds/Slapping_Three_Faces.wav";
		break;
	case 'm':
		sound_path = "../../Sounds/Wood_Plank_Flicks.wav";
		break;
	default:
		sound_path = "../../Sounds/Woodpecker.wav";
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