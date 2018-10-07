#include "menu.h"
#include "set_menu_strings.h"
#include "menu_actions.h"
#include "bass.h"
#include "press_and_save.h"

#include <iostream>
#include <stdlib.h>  
#include <crtdbg.h>
#include <vector>
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
	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	HSTREAM stream_handle; // Handle for open stream


	/* Initialize output device */
	BASS_Init(device, freq, 0, 0, NULL);

	/* Load your soundfile and play it */
	stream_handle = BASS_StreamCreateFile(FALSE, "your_file.mp3", 0, 0, 0);
	BASS_ChannelPlay(stream_handle, FALSE);

	/* As very last, close Bass */
 	BASS_Free(); 
	
	int action_index = 0;
	Menu main_menu(set_main_menu());
	Menu save_menu(set_save_menu());
	action_index = select_menu_action(main_menu);
	std::cout << std::endl << " action: " << action_index;
	if (action_index == 0)
	{
		action_index = select_menu_action(save_menu);
		if (action_index == 0)
		{
			// save as .mp3
		}
		else if (action_index == 1)
		{
			press_and_save_to_file();
		}
	}
	else if (action_index == 1)
	{
		// load menu
	}

	std::cout << std::endl << " Bye!";

    return 0;
}