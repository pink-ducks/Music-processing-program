#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <string>

void say_goodbye();

enum file_type {
	WAV, TXT
};

const std::string file_name_from_user(file_type type);

#endif 