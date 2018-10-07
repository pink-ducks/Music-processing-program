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
			this->options.at(index).insert(1, " ");
			this->index = this->index - 1;
			is_moved = true;
			this->options.at(index).insert(1, ">");
		}
	} else
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (this->index != this->options.size())
		{
			this->options.at(index).insert(1, " ");
			this->index = this->index + 1;
			is_moved = true;
			this->options.at(index).insert(1, ">");
		}
	}
	return is_moved;
}