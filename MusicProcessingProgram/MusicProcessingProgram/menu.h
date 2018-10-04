#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>

class Menu
{
    private:
		std::vector<std::string> options;

	public:
		Menu(std::vector<std::string> actions_strings)
		{
			options = actions_strings;
		}
		

		void show();
		~Menu() {};
};

#endif 