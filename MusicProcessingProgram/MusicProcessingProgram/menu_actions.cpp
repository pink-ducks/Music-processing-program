#include "menu_actions.h"
#include "menu.h"
#include "press_and_save.h"
#include "display_formatting.h"

int select_menu_action(Menu menu_object)
{
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	int current_index = 0;

	do
	{
		clear_screen();
		menu_object.show();
		getconchar(key);
		menu_object.move_arrow();
		current_index = menu_object.get_index();
		if (key.wVirtualKeyCode == VK_ESCAPE)
		{
			current_index = 2;
			break;
		}
	} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE);

	clear_screen();

	return current_index;
}

int run_menu(Menu & menu)
{
	int action_index = 0;
	action_index = select_menu_action(menu);
	std::cout << std::endl << " action: " << action_index;

	return action_index;
}

void manage_main_menu(int index, Menu & main_menu, Menu & save_menu, Menu & load_menu) // Menu & load_menu to add
{
	if (index == 0)
	{
		index = run_menu(save_menu);
		manage_save_menu(index, main_menu, save_menu, load_menu);
	}
	else if (index == 1)
	{
		index = run_menu(load_menu);
		manage_load_menu(index, main_menu, save_menu, load_menu);
	}
}

void manage_save_menu(int index, Menu & main_menu, Menu & save_menu, Menu & load_menu)
{
	if (index == 0)
	{
		// save ass .mp3
	}
	else if (index == 1)
	{
		press_and_save_to_file();
	}
	else
	{
		index = run_menu(main_menu);
		manage_main_menu(index, main_menu, save_menu, load_menu);
	}
}

void manage_load_menu(int index, Menu & main_menu, Menu & save_menu, Menu & load_menu)
{
	if (index == 0)
	{
		// load from .mp3
	}
	else if (index == 1)
	{
		//press_and_load_from_file();
	}
	else
	{
		index = run_menu(main_menu);
		manage_main_menu(index, main_menu, save_menu, load_menu);
	}
}