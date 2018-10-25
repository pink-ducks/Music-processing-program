#ifndef FILE_SUPPORT
#define FILE_SUPPORT
#include <string>

enum file_type {
	WAV, TXT
};

const std::string file_name_from_user(file_type type);

#endif