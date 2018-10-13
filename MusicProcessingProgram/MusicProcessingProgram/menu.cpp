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

void Menu::set_menu_type(menu_type type)
{
	this->type = type;
}

std::vector<std::string> Menu::get_vector() const
{
	return options;
}

int Menu::get_index() const
{
	return index;
}

menu_type Menu::get_menu_type() const
{
	return type;
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

void Menu::show() const
{
	upper_space();
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		center_text();
		std::cout << *i << std::endl;
	}
}