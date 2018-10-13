#include "menu.h"
#include <Windows.h>
#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

bool is_escape(const KEY_EVENT_RECORD key);

bool is_finished(const menu_type current_type, const Menu menu);

void main_menu_action(Menu & menu, KEY_EVENT_RECORD & key);

void save_menu_action(Menu & menu);

void load_menu_action(Menu & menu);

void switch_menu(menu_type & current_type, Menu & menu, KEY_EVENT_RECORD & key);

void choose_action(Menu & menu, KEY_EVENT_RECORD & key);

void run_menu(Menu & menu);

#endif