#include "display_formatting.h"
#include <iostream>
#include <iomanip>

#define VERTICAL_SPACING 4
#define HORIZONTAL_SPACE 50

void clear_screen()
{
	system("cls");
}

void multi_endl(int endl_number)
{
	for (int i = 0; i < endl_number; i++)
		std::cout << std::endl;
}

void upper_space()
{
	multi_endl(VERTICAL_SPACING);
}

void center_text()
{
	std::cout << std::setw(HORIZONTAL_SPACE);
}

