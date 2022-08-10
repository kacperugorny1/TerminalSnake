#pragma once
#include <vector>

enum direction
{
	FOWARD = 0,
	BACK = 1,
	LEFT = 2,
	RIGHT = 3
};


class Snake
{
	int pos_x;
	int pos_y;
	int tail_length;
	direction head;
	std::vector<int> tail_x;
	std::vector<int> tail_y;


public:
	int get_x() { return pos_x; }
	int get_y() { return pos_y; }
	Snake();
	void update_pos();
	char is_here_smth(int x, int y, int fx, int fy);
	void keys_check();
	void add_tail();
	bool head_tail_collision();

};

