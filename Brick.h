#pragma once
#include <vector>
using namespace std;

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
	void set_bricks();
	void delete_bricks(int n);			// n is brick number
	void clear_bricks();
	void score_print();
	int score_add();
	void print();
	void reset_bricks();
	void print_bricks();
private:
	int mode;				// mode signal
	int score_signal;		// score signal
	int sum_bricks = 60;
	int score = 0;
	int goto_x = 5;
	int goto_y = 3;
	vector<Coord> all_bricks;
};

