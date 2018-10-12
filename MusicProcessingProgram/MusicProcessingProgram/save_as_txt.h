#ifndef SAVE_AS_TXT_H
#define SAVE_AS_TXT_H
#include <fstream>
#include <iostream>
#include <Windows.h>

bool getconchar(KEY_EVENT_RECORD& krec);

void press_and_save_to_file(std::string file_path);

void save_as_txt();

#endif