#include "Snake.h"
#include <windows.h>
#include <conio.h>
#include<array>



Snake::Snake() {
	pos_x = 24;
	pos_y = 15;
	tail_length = 0;
	head = FOWARD;

	
}

char Snake::is_here_smth(int x, int y, int fx, int fy) {
	if (x == pos_x && y == pos_y)
		return 'O';
	else if (x == fx && y == fy)
		return 'F';
	else {
		for (int i = 0; i < tail_length; ++i) {
			if (x == tail_x[i] && y == tail_y[i])
				return 'o';
		}
		return ' ';
	}
}

void Snake::keys_check() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (head == RIGHT)
				return;
			head = LEFT;
			break;
		case 'd':
			if (head == LEFT)
				return;
			head = RIGHT;
			break;
		case 'w':
			if (head == BACK)
				return;
			head = FOWARD;
			break;
		case 's':
			if (head == FOWARD)
				return;
			head = BACK;
			break;
		}
	}
}


void Snake::update_pos() {
	for (int i = tail_length; i > 1; --i) {
		tail_x[i - 1] = tail_x[i - 2];
		tail_y[i - 1] = tail_y[i - 2];
	}
	if (tail_length > 0) {
		tail_x[0] = pos_x;
		tail_y[0] = pos_y;
	}
	switch (head)
	{
	case FOWARD:
		pos_y--;
		break;
	case BACK:
		pos_y++;
		break;
	case LEFT:
		pos_x--;
		break;
	case RIGHT:
		pos_x++;
		break;
	}
}
void Snake::add_tail() {
	std::array<int, 2> pos_tail;
	if (tail_x.size() == 0) {
		pos_tail[0] = pos_x;
		pos_tail[1] = pos_y;
	}
	else {
		pos_tail[0] = tail_x.back();
		pos_tail[1] = tail_y.back();
	}
	tail_x.push_back(pos_tail[0]);
	tail_y.push_back(pos_tail[1]);
	tail_length++;
}

bool Snake::head_tail_collision() {
	for (int i = 0; i < tail_length; ++i)
		if (pos_x == tail_x[i] && pos_y == tail_y[i])
			return true;
	return false;
}