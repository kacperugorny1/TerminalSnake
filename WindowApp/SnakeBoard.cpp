#include "SnakeBoard.h"

SnakeBoard::SnakeBoard() {
	width = 40;
	length = 20;
	score = 0;
	Fruit.generate(width,length);
}


// print window
void SnakeBoard::print_window() {
	int Fx = Fruit.get_x();
	int Fy = Fruit.get_y();
	system("CLS");
	std::cout << std::string(width, '#') << std::endl;
	for (int i = 1; i < length - 1; ++i) {
		std::cout << "#";
		for (int j = 1; j < width - 1; ++j) {
			std::cout<<Snake.is_here_smth(j,i,Fx,Fy);
		}
		std::cout << '#' << std::endl;

	}
	std::cout << std::string(width, '#')<<std::endl;
	std::cout << "Score : " << score << std::endl;


}

// check collisions
bool SnakeBoard::check_collisions() {
	
	// collsion with walls
	if (Snake.get_y() >= length - 1 || Snake.get_y() < 1)
		return true;
	if (Snake.get_x() >= width - 1 || Snake.get_x() < 1)
		return true;
	
	
	if (Snake.head_tail_collision())
		return true;

	

	// collect fruit then add tail then generate new fruit location
	if (Snake.get_x() == Fruit.get_x() && Snake.get_y() == Fruit.get_y()) {
		Fruit.generate(width, length);
		Snake.add_tail();
		score += 10;
	}
	return false;
}