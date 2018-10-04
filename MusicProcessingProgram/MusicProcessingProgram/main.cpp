#include "menu.h"
#include "menu_vectors.h"
#include "bass.h"
int main()
{
	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	HSTREAM streamHandle; // Handle for open stream
	BASS_Init(device, freq, 0, 0, NULL);


	Menu main_menu(main_menu_strings);
	main_menu.show();

    return 0;
}

