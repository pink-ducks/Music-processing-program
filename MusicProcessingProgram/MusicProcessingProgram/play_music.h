#ifndef PLAY_MUSIC_H
#define PLAY_MUSIC_H
#include <string>
#include <vector>

std::string find_sound(const char key);

void play_sound(const char key);

void play_music(const std::string file_name);

void play_users_music(std::vector<char> keys);

#endif 