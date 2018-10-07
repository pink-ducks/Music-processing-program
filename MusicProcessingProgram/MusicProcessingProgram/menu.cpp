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

bool Menu::move_arrow()
{
	bool is_moved = false;
	if (GetAsyncKeyState(VK_UP))
	{
		if (this->index != 0)
		{
			this->index = this->index - 1;
			is_moved = true;
		}
	} else
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (this->index != this->options.size())
		{
			this->index = this->index + 1;
			is_moved = true;
		}
	}
	return is_moved;
}