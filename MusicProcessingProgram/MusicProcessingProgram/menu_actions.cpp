#include "menu_actions.h"
#include "menu.h"
#include "save_as_txt.h"
#include "display_formatting.h"
#include "set_menu_strings.h"
#include "communication.h"
#include "play_music.h"
#include "load_music.h"

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

bool is_finished(const menu_type current_type, const Menu menu)
{
	bool is_finished = false;
	if (current_type == LOAD)
	{
		if (menu.get_index() == 0 || menu.get_index() == 1)
		{
			is_finished = true;
		}
	}
	else
	if(current_type == SAVE)
	{
		if (menu.get_index() == 0)
		{
			is_finished = true;
		}
	}

	return is_finished;
}

void main_menu_action(Menu & menu, KEY_EVENT_RECORD & key)
{
	switch (menu.get_index())
	{
	case 0:
		menu.set_vector(return_save_menu());
		menu.set_menu_type(SAVE);
		break;
	case 1:
		menu.set_vector(return_load_menu());
		menu.set_menu_type(LOAD);
		break;
	case 2:
		key.wVirtualKeyCode = VK_ESCAPE;
		break;
	default:
		break;
	}
}

void save_menu_action(Menu & menu)
{
	switch (menu.get_index())
	{
	case 0:
		save_as_txt();
		break;
	case 1:
		menu.set_vector(return_main_menu());
		menu.set_menu_type(MAIN);
		break;
	default:
		break;
	}
}

void load_menu_action(Menu & menu)
{
	std::string file_name;
	switch (menu.get_index())
	{
	case 0: 
		file_name = file_name_from_user(WAV);
		play_music(file_name);
		break;
	case 1:
		file_name = file_name_from_user(TXT);
		play_from_file(file_name);
		break;
	case 2:
		menu.set_vector(return_main_menu());
		menu.set_menu_type(MAIN);
		break;
	default:
		break;
	}
}

void switch_menu(menu_type & current_type, Menu & menu, KEY_EVENT_RECORD & key)
{
	switch (current_type)
	{
	case MAIN:
		main_menu_action(menu, key);
		break;
	case SAVE:
		save_menu_action(menu);
		break;
	case LOAD:
		load_menu_action(menu);
		break;
	default:
		break;
	}
}

void choose_action(Menu & menu, KEY_EVENT_RECORD & key)
{
	do
	{
		clear_screen();
		menu.show();
		getconchar(key);
		menu.move_arrow();

	} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE && key.wVirtualKeyCode != VK_ESCAPE);
}

void run_menu(Menu & menu)
{
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	menu.set_vector(return_main_menu());
	
	do
	{
		menu.set_index(0);
		menu_type current_type = menu.get_menu_type();

		choose_action(menu, key);
		switch_menu(current_type, menu, key);
	
		if (is_finished(current_type, menu))
			break;

	} while (!is_escape(key));
}
