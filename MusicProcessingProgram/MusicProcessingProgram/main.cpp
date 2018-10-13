#include "menu.h"
#include "menu_actions.h"
#include "play_music.h"
#include "communication.h"

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
	play_sound("../../Sounds/crash.wav"); // delete this line with include "music.h" after playing sounds in other functions
	
	Menu menu;
	run_menu(menu);
	say_goodbye();

    return 0;
}