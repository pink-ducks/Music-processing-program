#include "menu.h"
#include "bass.h"
#include "press_and_save.h"
#include "display_formatting.h"

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
	std::vector<std::string> main_menu_strings
	{
		"> Create new sounds!",
		"  Play music from a file",
		"  Quit :("
	};

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
	

	Menu main_menu(main_menu_strings);

	main_menu.show();
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		if (main_menu.move_arrow())
		{
			clear_screen();
			main_menu.show();
			break;
		}
	}
    return 0;
}