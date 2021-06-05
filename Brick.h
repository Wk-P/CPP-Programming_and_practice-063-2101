#pragma once
#include <vector>
using namespace std;

#define BrickWidth 2
#define BrickHeight 1

class Coord {
public:
	int get_x();
	int get_y();
	void set_coord(int, int);
	void display_set();
	void blank_set();
	int get_display_signal();
private:
	int x;
	int y;
	int display_signal = 1;
};

class Brick
{
public:
	void set_bricks(int, int);
	void delete_bricks(int n);			// n is brick number
	void clear_bricks();
	void score_print();
	int score_add();
	void reset_bricks();
	void Render();
	int get_display_signal(int, int);
	int get_x(int, int);
	int get_y(int, int);
private:				
	int sum_bricks = 60;
	int score = 0;
	int start_x = 3;
	int start_y = 5;
	int all_bricks[60][3];		//x, y, display_signal
};

