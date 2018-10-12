#include "communication.h"
#include "display_formatting.h"
#include <iostream>

void say_goodbye()
{
	clear_screen();
	std::cout << std::endl << " Bye!";
}
