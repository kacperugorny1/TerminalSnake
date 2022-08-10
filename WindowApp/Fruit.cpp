#include "Fruit.h"


//Generate fruit location
void Fruit::generate(int width, int length) {
	pos_x = rand() % (width - 2) + 1;
	pos_y = rand() % (length - 2) + 1;
}