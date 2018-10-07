#include "menu.h"
#include "display_formatting.h"
#include <Windows.h>
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

int Menu::move_arrow()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (index != 0)
		{
			options.at(index).replace(0, 1, " ");
			index = index - 1;
			options.at(index).replace(0, 1, ">");
		}
	} else
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (index != options.size() - 1)
		{
			options.at(index).replace(0, 1, " ");
			index = index + 1;
			options.at(index).replace(0, 1, ">");
		}
	}
	return index;
}
