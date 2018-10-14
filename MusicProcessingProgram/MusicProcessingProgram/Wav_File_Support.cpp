#include "Wav_File_Support.h"
#include <iostream>
#include <string>
#include <fstream>

void load_Wave_File(char *fname, WavData *ret) {

	FILE* fp = fopen(fname, "rb");
	if (fp) {
		char id[5];
		unsigned long size;
		short format_tag, channels, block_align, bits_per_sample;
		unsigned long format_length, sample_rate, avg_bytes_sec, data_size;

		fread(id, sizeof(char), 4, fp);
		id[4] = '\0';

		if (!strcmp(id, "RIFF")) {
			fread(&size, sizeof(unsigned long), 1, fp);
			fread(id, sizeof(char), 4, fp);
			id[4] = '\0';

			if (!strcmp(id, "WAVE")) {
				fread(id, sizeof(char), 4, fp);
				fread(&format_length, sizeof(unsigned long), 1, fp);
				fread(&format_tag, sizeof(short), 1, fp);
				fread(&channels, sizeof(short), 1, fp);
				fread(&sample_rate, sizeof(unsigned long), 1, fp);
				fread(&avg_bytes_sec, sizeof(unsigned long), 1, fp);
				fread(&block_align, sizeof(short), 1, fp);
				fread(&bits_per_sample, sizeof(short), 1, fp);
				fread(id, sizeof(char), 4, fp);
				fread(&data_size, sizeof(unsigned long), 1, fp);

				ret->size = data_size / sizeof(short);
				ret->data = (short*)malloc(data_size);
				fread(ret->data, sizeof(short), ret->size, fp);
			}
			else {
				std::cout << "Error: RIFF file but not a wave file\n";
			}
		}
		else {
			std::cout << "Error: not a RIFF file\n";
		}
	}
	fclose(fp);
}
