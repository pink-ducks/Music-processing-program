#include "menu.h"
#include <Windows.h>
#ifndef MENU_ACTIONS_H
#define MENU_ACTIONS_H

bool is_escape(const KEY_EVENT_RECORD key); // returns true ==> finish program

bool is_finished(const menu_type current_type, const Menu menu); 
// is_finished checks if program did his job 
// returns true ==> finish program
// terurns false ==> user chose 'back'

void main_menu_action(Menu & menu, KEY_EVENT_RECORD & key);
// function changes main menu to: save menu/load menu OR exits the program

void save_menu_action(Menu & menu);
// function runs saving functions or change menu to main

void load_menu_action(Menu & menu);
// function runs load function or change menu to main

void switch_menu(menu_type & current_type, Menu & menu, KEY_EVENT_RECORD & key);
// function checks menu_type and calls the appropriate functions

void choose_action(Menu & menu, KEY_EVENT_RECORD & key);
// function showing menu and moves arrow until the user enter

void run_menu(Menu & menu);

#endif