#include "menu.h"
#include <iostream>

void Menu::show()
{
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}

