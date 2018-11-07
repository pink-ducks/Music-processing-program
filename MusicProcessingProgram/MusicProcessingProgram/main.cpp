#include "menu.h"
#include "menu_actions.h"
#include "communication.h"
#include "check_memory_leaks.h"

int main()
{
	Menu menu;
	run_menu(menu);
	say_goodbye();

    return 0;
}