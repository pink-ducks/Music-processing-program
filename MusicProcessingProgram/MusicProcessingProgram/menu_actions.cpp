#include "menu_actions.h"
#include "menu.h"
#include "save_as_txt.h"
#include "display_formatting.h"
#include "set_menu_strings.h"

bool is_escape(const KEY_EVENT_RECORD key)
{
	bool escape_clicked = true;
	if (key.wVirtualKeyCode == VK_ESCAPE)
	{
		escape_clicked = true;
	}
	else
	{
		escape_clicked = false;
	}
	return escape_clicked;
}

bool go_from_main_menu(Menu & menu)
{
	bool is_entered = true;
	if (menu.get_index() == 0 && menu.get_vector()[0] == "> Create new sounds!")
	{
		menu.set_vector(return_save_menu());
	}
	else
	if (menu.get_index() == 1 && menu.get_vector()[1] == "> Play music from a file")
	{
		menu.set_vector(return_load_menu());
	}
	else
	if (menu.get_index() == 2 && menu.get_vector()[2] == "> Quit :(")
	{
		is_entered = false;
	}
	return is_entered;
}

bool go_from_save_menu(Menu & menu)
{
	bool is_choosed = false;
	if (menu.get_index() == 0 && menu.get_vector()[0] == "> Save as .mp3")
	{
		// save as .mp3
	}
	else
	if (menu.get_index() == 1 && menu.get_vector()[1] == "> Save as .txt")
	{
		save_as_txt();
		is_choosed = true;
	}
	else
	if (menu.get_index() == 2 && menu.get_vector()[2] == "> Back")
	{
		menu.set_vector(return_main_menu());
	}
	return is_choosed;
}

bool go_from_load_menu(Menu & menu)
{
	bool is_choosed = false;
	if (menu.get_index() == 0 && menu.get_vector()[0] == "> Load from .mp3")
	{
		// load from .mp3
	}
	else
	if (menu.get_index() == 1 && menu.get_vector()[1] == "> Load from .txt")
	{
		// load from .txt
	}
	else
	if (menu.get_index() == 2 && menu.get_vector()[2] == "> Back")
	{
		menu.set_vector(return_main_menu());
	}
	return is_choosed;
}

void run_menu(Menu & menu)
{
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	menu.set_vector(return_main_menu());
	
	do
	{
		menu.set_index(0);
		do
		{
			clear_screen();
			menu.show();
			getconchar(key);
			menu.move_arrow();

		} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE && key.wVirtualKeyCode != VK_ESCAPE);
		if (!go_from_main_menu(menu) || key.wVirtualKeyCode == VK_ESCAPE)
		{
			break;
		}
		else
		{
			if (go_from_save_menu(menu))
				break;
			if (go_from_load_menu(menu))
				break;
		}

	} while (!is_escape(key));
}
