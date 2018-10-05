#include "display_formatting.h"
#include <iostream>

void multi_endl(int endl_number)
{
	for (int i = 0; i < endl_number; i++)
		std::cout << std::endl;
}