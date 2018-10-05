#include "menu.h"
#include "display_formatting.h"
#include <iostream>

#define VERTICAL_SPACING 4

void Menu::show()
{
	multi_endl(VERTICAL_SPACING);
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}
