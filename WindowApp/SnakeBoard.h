#pragma once
#include <string>
#include <iostream>
#include "Snake.h"
#include "Fruit.h"


class SnakeBoard
{
	int width;
	int length;
	int score;
	Snake Snake;
	Fruit Fruit;


public:
	SnakeBoard();
	void print_window();
	void update_snake_pos() {Snake.update_pos();}
	void keys_check() { Snake.keys_check(); }
	bool check_collisions();
};