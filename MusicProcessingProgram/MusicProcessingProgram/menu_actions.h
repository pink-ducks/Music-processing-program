#include "menu.h"
#include <Windows.h>
#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

bool is_escape(const KEY_EVENT_RECORD key);

bool go_from_main_menu(Menu & menu);

bool go_from_save_menu(Menu & menu);

bool go_from_load_menu(Menu & menu);

void run_menu(Menu & menu);

#endif