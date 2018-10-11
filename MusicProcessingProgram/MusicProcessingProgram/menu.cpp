#include "menu.h"
#include "display_formatting.h"
#include <Windows.h>
#include <iostream>

void Menu::set_vector(std::vector<std::string> options)
{
	this->options = options;
}

void Menu::set_index(int index)
{
	this->index = index;
}

int Menu::get_index()
{
	return index;
}

void Menu::move_arrow()
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
}

void Menu::show()
{
	upper_space();
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		center_text();
		std::cout << *i << std::endl;
	}
}