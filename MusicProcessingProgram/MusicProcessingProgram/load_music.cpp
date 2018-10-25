#include "load_music.h"
#include "play_music.h"
#include <iostream>
#include <fstream>

void play_from_file(const std::string file_name)
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
		std::cout << " ERROR: Unable to open file!" << std::endl;
	}
	myfile.close();
}
