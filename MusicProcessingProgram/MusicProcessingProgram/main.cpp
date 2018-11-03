#include "menu.h"
#include "menu_actions.h"
#include "communication.h"
#include <span class="code-string">"Wave.h"</span>
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
	Menu menu;
	run_menu(menu);
	say_goodbye();

	return 0;
}
