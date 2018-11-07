#ifndef DISPLAY_FORMATTING_H
#define DISPLAY_FORMATTING_H

void clear_screen();

void multi_endl(int endl_number); 
// multi_endl(3) ==> std::cout << std::endl << std::endl << std::endl;

void upper_space(); // to make vertical space (4 lines)

void center_text(); // to make horizontal space (50 characters)

#endif 