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
		current_index = menu_object.move_arrow();
		if (key.wVirtualKeyCode == VK_ESCAPE)
		{
			current_index = 2;
			break;
		}
	} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE);

	clear_screen();

	return current_index;
}