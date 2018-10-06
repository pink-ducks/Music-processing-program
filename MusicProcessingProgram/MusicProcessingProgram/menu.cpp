#include "menu.h"
#include "display_formatting.h"
#include <iostream>

void Menu::show()
{
	upper_space();
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		center_text();
		std::cout << *i << std::endl;
	}
}
