#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>

enum menu_type {
	MAIN, SAVE, LOAD
};

class Menu
{
    private:
		std::vector<std::string> options;
		int index = 0;
		menu_type type;
	public:
		Menu() {};
		Menu(std::vector<std::string> options)
		{
			this->options = options;
			index = 0;
		}

		void set_vector(std::vector<std::string>);
		void set_index(int);
		void set_menu_type(menu_type type);

		std::vector<std::string> get_vector() const;
		int get_index() const;
		menu_type get_menu_type() const;

		void move_arrow();
		void show() const;
		~Menu() {};
};

#endif 