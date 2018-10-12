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
		Menu() {};
		Menu(std::vector<std::string> options)
		{
			this->options = options;
			index = 0;
		}

		void set_vector(std::vector<std::string>);
		void set_index(int);

		int get_index() const;
		std::vector<std::string> get_vector() const;

		void move_arrow();
		void show() const;
		~Menu() {};
};

#endif 