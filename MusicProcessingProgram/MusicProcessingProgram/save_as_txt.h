#ifndef SAVE_AS_TXT_H
#define SAVE_AS_TXT_H
#include <Windows.h>
#include <vector>

bool getconchar(KEY_EVENT_RECORD& krec);

void save_as_txt();

void save_to_file(const std::vector<char> keys, const std::string file_path);

void read_from_file(const std::string file_name);

void load_from_file();

#endif