#include "play_music.h"
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <crtdbg.h>

void play_sound(const std::string sound_path)
{
	// converting std::string to LPCWSTR
	std::wstring stemp = std::wstring(sound_path.begin(), sound_path.end());
	LPCWSTR path = stemp.c_str();

	std::cout << " *music*" << std::endl;
	PlaySound(path, NULL, SND_SYNC);
}
