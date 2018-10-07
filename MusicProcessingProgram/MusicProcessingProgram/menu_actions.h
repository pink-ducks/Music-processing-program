#include "menu.h"
#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

int select_menu_action(Menu menu_object);

int run_menu(Menu & menu);

void manage_main_menu(int index, Menu & main_menu, Menu & save_menu);

void manage_save_menu(int index, Menu & main_menu, Menu & save_menu);

#endif