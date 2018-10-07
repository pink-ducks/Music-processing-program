#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>

class Menu
{
    private:
		std::vector<std::string> options;
		int index;
	public:
		Menu(std::vector<std::string> actions_strings)
		{
			options = actions_strings;
			index = 0;
		}
		
		bool move_arrow();
		void show();
		~Menu() {};
};

#endif 