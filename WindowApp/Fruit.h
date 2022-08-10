#pragma once
#include <cstdlib>
class Fruit
{
	int pos_x;
	int pos_y;

public:
	Fruit() { pos_x = 0; pos_y = 0; }
	int get_x() { return pos_x; }
	int get_y() { return pos_y; }
	void generate(int width, int length);
};

