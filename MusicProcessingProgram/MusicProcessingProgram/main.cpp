#include "menu.h"
#include "set_menu_strings.h"
#include "menu_actions.h"
#include "press_and_save.h"
#include "File_Support.h"
#include <Windows.h>
#include <MMSystem.h>
#include <crtdbg.h>
#include <string>
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
	//playing random music
	if (PlaySound(TEXT("../sounds/a.wav"), NULL, SND_SYNC))
	{
		system("pause");
	}
	
	int menu_index = 0;
	Menu main_menu(set_main_menu());
	Menu save_menu(set_save_menu());
	Menu load_menu(set_load_menu());
	menu_index = run_menu(main_menu);
	manage_main_menu(menu_index, main_menu, save_menu, load_menu);

	std::cout << std::endl << " Bye!";

    return 0;
}