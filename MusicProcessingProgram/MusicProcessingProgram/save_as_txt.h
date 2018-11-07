#ifndef SAVE_AS_TXT_H
#define SAVE_AS_TXT_H
#include <Windows.h>
#include <vector>

bool getconchar(KEY_EVENT_RECORD& krec); // waiting for keyboard hit 

void save_as_txt(); // saves keyboard keys in vector -> plays music from vector -> gets file name -> saves file

void save_to_file(const std::vector<char> keys, const std::string file_path); // saves vector in txt file

#endif