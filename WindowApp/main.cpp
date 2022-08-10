#include <iostream>
#include "SnakeBoard.h"
#include <windows.h>


int main() {
	SnakeBoard Board;
	
	while (true) {
		Board.print_window();
		Board.keys_check();
		Board.update_snake_pos();
		if (Board.check_collisions())
			break;
		Sleep(10);
	}
	std::cin.clear();
	system("CLS");
	Board.print_window();
	getchar();
	
	return 0;
}