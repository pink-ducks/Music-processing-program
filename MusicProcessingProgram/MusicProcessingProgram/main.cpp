#include "menu.h"
#include "set_menu_strings.h"
#include "menu_actions.h"
#include "music.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC

struct AtExit
{
	~AtExit()
	{
		_CrtDumpMemoryLeaks();
		// breakpoint to check memory leaks after main
	}
} doAtExit;

int main()
{
	// playing random music
	play_sound("../sounds/test.wav");
	
	// menu
	int menu_index = 0;
	Menu main_menu(return_main_menu());
	Menu save_menu(return_save_menu());
	Menu load_menu(return_load_menu());
	menu_index = run_menu(main_menu);
	manage_main_menu(menu_index, main_menu, save_menu, load_menu);

	std::cout << std::endl << " Bye!";

    return 0;
}