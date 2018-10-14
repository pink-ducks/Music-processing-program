#ifndef WAV_FILE_SUPPORT_H
#define WAV_FILE_SUPPORT_H

#include <iostream>
#include <string>
#include <fstream>
class WavData {
public:
	short* data;
	unsigned long size;

	WavData() {
		data = nullptr;
		size = 0;
	}
};
void load_Wave_File(char *fname, WavData *ret);

#endif 
